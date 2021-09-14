//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Dialogs.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.ImgList.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ToolWin.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TButton *ButtonPgBack;
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Exit1;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TImageList *ImageList1;
	TRadioGroup *RadioGroup1;
	TEdit *EditFilter;
	TListBox *ListBox1;
	TRadioGroup *RadioGroup2;
	TRadioGroup *RadioGroup3;
	TListBox *ListBox3;
	TEdit *EditSearchStr;
	TLabel *Label1;
	void __fastcall ButtonPgBackClick(TObject *Sender);
	void __fastcall RadioGroup3Click(TObject *Sender);
	void __fastcall RadioGroup1Click(TObject *Sender);
	void __fastcall Exit1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
