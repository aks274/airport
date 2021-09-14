// ---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
// ---------------------------------------------------------------------------

#include <Vcl.OleCtrls.hpp>
#include <System.Classes.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.ToolWin.hpp>
#include <vector>
#include <algorithm>
#include <functional>
// ---------------------------------------------------------------------------

struct staff {

	char company[20];
	char airbus[20];
	char country[20];
	char city[20];
	int cost;

	friend bool operator < (const staff& a, const staff& b) {
		return a.cost < b.cost;
	} // for sort by pay

	friend bool sortcomp(const staff& a, const staff& b) {
		return strcmp(a.company, b.company) < 0;
	}

	friend bool sortair(const staff& a, const staff& b) {
		return strcmp(a.airbus, b.airbus) < 0;
	}

	friend bool sortcountry(const staff& a, const staff& b) {
		return strcmp(a.country, b.country) < 0;
	}

	friend bool sortcity(const staff& a, const staff& b) {
		return strcmp(a.city, b.city) < 0;
	}

	friend bool operator == (const staff& a, const staff& b)

	{
		return a.cost == b.cost;
	} // for search by pay

};

using namespace std;
extern vector<staff>crew;
extern int iMax, iCur;

class TForm1 : public TForm {
__published: // IDE-managed Components

	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *OpenAs1;
	TMenuItem *SaveAs1;
	TMenuItem *N1;
	TMenuItem *Exit1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TLabel *Label1;
	TEdit *EditCompany;
	TLabel *Label2;
	TEdit *EditAirbus;
	TLabel *Label3;
	TEdit *EditCountry;
	TEdit *EditCity;
	TLabel *Label4;
	TLabel *Label5;
	TEdit *EditCost;
	TLabel *LabelNum;
	TButton *ButtonAdd;
	TButton *ButtonPrev;
	TButton *ButtonNext;
	TButton *ButtonDelete;
	TButton *ButtonChange;
	TImageList *ImageList1;
	TToolBar *ToolBar1;
	TToolButton *ToolButton1;
	TToolButton *ToolButton2;
	TToolButton *ToolButton3;
	TToolButton *ToolButton4;
	TToolButton *ToolButton5;
	TButton *ButtonPgNext;
	TGroupBox *GroupBox1;
	TLabel *Label6;
	TEdit *EditSearch;
	TButton *ButtonSearch;
	TButton *ButtonSort;
	TMenuItem *H1;
	TMenuItem *Sort1;
	TMenuItem *By1;
	TMenuItem *by2;
	TMenuItem *by3;
	TMenuItem *by4;
	TLabel *Label7;

	void __fastcall Exit1Click(TObject *Sender);
	void __fastcall OpenAs1Click(TObject *Sender);
	void __fastcall SaveAs1Click(TObject *Sender);
	void __fastcall ButtonAddClick(TObject *Sender);
	void __fastcall ButtonPrevClick(TObject *Sender);
	void __fastcall ButtonNextClick(TObject *Sender);
	void __fastcall ButtonChangeClick(TObject *Sender);
	void __fastcall ButtonDeleteClick(TObject *Sender);
	void __fastcall ButtonPgNextClick(TObject *Sender);
	void __fastcall ButtonSearchClick(TObject *Sender);
	void __fastcall ButtonSortClick(TObject *Sender);
	void __fastcall by4Click(TObject *Sender);
	void __fastcall Sort1Click(TObject *Sender);
	void __fastcall By1Click(TObject *Sender);
	void __fastcall by2Click(TObject *Sender);
	void __fastcall by3Click(TObject *Sender);

private: // User declarations
		public : // User declarations
	__fastcall TForm1(TComponent* Owner);
	void __fastcall ShowRecord();
};

// ---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
// ---------------------------------------------------------------------------
#endif
