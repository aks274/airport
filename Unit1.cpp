// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit2.h"
#include "Unit1.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

vector<staff>crew;
int iMax = 0, iCur = 0;

// ---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::Exit1Click(TObject *Sender) {
	Form1->Close();
	Form2->Close();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::OpenAs1Click(TObject *Sender) {
	OpenDialog1->Execute();

	FILE *f = fopen(AnsiString(OpenDialog1->FileName).c_str(), "rb");
	if (f == 0) {
		ShowMessage("������ �����!");
		return;
	}

	crew.clear();

	for (int i = 0; i < crew.max_size(); i++) {
		staff s;
		fread(&s, sizeof(staff), 1, f);
		if (feof(f))
			break;
		crew.push_back(s);
	}
	fclose(f);
	iMax = crew.size();
	iCur = 0;
	ShowRecord();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::SaveAs1Click(TObject *Sender) {
	SaveDialog1->Execute();
	FILE *f = fopen(AnsiString(SaveDialog1->FileName).c_str(), "wb");
	if (f)
		fwrite(&crew[0], sizeof(staff), iMax, f);
	else
		ShowMessage("������ �����");
	fclose(f);
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonAddClick(TObject *Sender) {
	crew.push_back(staff());
	AnsiString C = EditCompany->Text;
	AnsiString A = EditAirbus->Text;
	AnsiString Co = EditCountry->Text;
	AnsiString Ci = EditCity->Text;
	AnsiString pr = EditCost->Text;
	strcpy(crew[iMax].company, ((AnsiString)EditCompany->Text).c_str());
	strcpy(crew[iMax].airbus, ((AnsiString)EditAirbus->Text).c_str());
	strcpy(crew[iMax].country, ((AnsiString)EditCountry->Text).c_str());
	strcpy(crew[iMax].city, ((AnsiString)EditCity->Text).c_str());
	crew[iMax].cost = EditCost->Text.ToIntDef(0);
	if (C.Length() == 0 || A.Length() == 0 || Co.Length() == 0 ||
		Ci.Length() == 0 || pr.Length() == 0) {
		ShowMessage("������� ��������!");
	}
	else {
		ShowMessage("������ ���������!");
		iCur = iMax;
		iMax++;
		LabelNum->Caption = IntToStr(iMax);
	}

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::ShowRecord() {
	if (iMax == 0) {
		EditCompany->Text = "";
		EditAirbus->Text = "";
		EditCountry->Text = "";
		EditCity->Text = "";
		EditCost->Text = "";
		LabelNum->Caption = "0";
		return;
	}
	EditCompany->Text = crew[iCur].company;
	EditAirbus->Text = crew[iCur].airbus;
	EditCountry->Text = crew[iCur].country;
	EditCity->Text = crew[iCur].city;
	EditCost->Text = IntToStr(crew[iCur].cost);
	LabelNum->Caption = IntToStr(iCur + 1);

}

// ---------------------------------------------------------------------------
void __fastcall TForm1::ButtonPrevClick(TObject *Sender) {
	if (iCur <= 0)
		return;
	iCur--;
	ShowRecord();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonNextClick(TObject *Sender) {
	if (iCur >= iMax - 1)
		return;
	iCur++;
	ShowRecord();
}

// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonChangeClick(TObject *Sender) {
	AnsiString C = EditCompany->Text;
	AnsiString A = EditAirbus->Text;
	AnsiString Co = EditCountry->Text;
	AnsiString Ci = EditCity->Text;
	AnsiString pr = EditCost->Text;
	if (C.Length() == 0 || A.Length() == 0 || Co.Length() == 0 ||
		Ci.Length() == 0 || pr.Length() == 0) {
		ShowMessage("������� ��������!");
	}
	else {
		strcpy(crew[iCur].company, ((AnsiString)EditCompany->Text).c_str());
		strcpy(crew[iCur].airbus, ((AnsiString)EditAirbus->Text).c_str());
		strcpy(crew[iCur].country, ((AnsiString)EditCountry->Text).c_str());
		strcpy(crew[iCur].city, ((AnsiString)EditCity->Text).c_str());
		crew[iCur].cost = EditCost->Text.ToIntDef(0);
		ShowMessage("������� ��������!");
	}

}
// ---------------------------------------------------------------------------

// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonDeleteClick(TObject *Sender) {
	if (iMax == 0) {
		ShowMessage("���� �����!");
		return;
	}

	crew.erase(crew.begin() + iCur);
	iMax--;
	iCur--;
	ShowRecord();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonPgNextClick(TObject *Sender) {
	Form2->Show();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSearchClick(TObject *Sender) {
	if (EditSearch->Text.ToIntDef(0) == 0) {
		ShowMessage("������� �����!");
	}
	else {
		try {
			staff s;
			vector<staff>::iterator p;
			s.cost = EditSearch->Text.ToIntDef(0);
			p = find(crew.begin(), crew.end(), s);
			iCur = p - crew.begin();
			if (crew[iCur].cost == 0) {
				ShowMessage("������ �� �������!");
				iCur = 0;
			}
			else {
				ShowRecord();
			}
		}
		catch (...) {
			ShowMessage("������ �����������");
		};
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::ButtonSortClick(TObject *Sender) {
	AnsiString C = EditCompany->Text;
	AnsiString A = EditAirbus->Text;
	AnsiString Co = EditCountry->Text;
	AnsiString Ci = EditCity->Text;
	AnsiString pr = EditCost->Text;
	if (C.Length() == 0 || A.Length() == 0 || Co.Length() == 0 ||
		Ci.Length() == 0 || pr.Length() == 0) {
		ShowMessage("������� ��������!");
	}
	else
		sort(crew.begin(), crew.end());
	iCur = 0;
	ShowRecord();
}

// ---------------------------------------------------------------------------
void __fastcall TForm1::by4Click(TObject *Sender) {
	sort(crew.begin(), crew.end());
	iCur = 0;
	ShowRecord();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::Sort1Click(TObject *Sender) {
	sort(crew.begin(), crew.end(), &sortcomp);
	iCur = 0;
	ShowRecord();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::By1Click(TObject *Sender) {
	sort(crew.begin(), crew.end(), &sortair);
	iCur = 0;
	ShowRecord();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::by2Click(TObject *Sender) {
	sort(crew.begin(), crew.end(), &sortcountry);
	iCur = 0;
	ShowRecord();
}
// ---------------------------------------------------------------------------

void __fastcall TForm1::by3Click(TObject *Sender) {
	sort(crew.begin(), crew.end(), &sortcity);
	iCur = 0;
	ShowRecord();
}
// ---------------------------------------------------------------------------
