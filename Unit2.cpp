// ---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Unit1.h"
#include "Unit2.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;

// ---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner) : TForm(Owner) {
}

// ---------------------------------------------------------------------------

void __fastcall TForm2::ButtonPgBackClick(TObject *Sender) {
	Form1->Show();
    Form2->Hide();
}

// ---------------------------------------------------------------------------
void __fastcall TForm2::RadioGroup3Click(TObject *Sender) {
	ListBox3->Items->Clear();
	iCur = -1;
	int a = 0;
	switch (RadioGroup3->ItemIndex) {
	case 0: {
			for (int i = 0; i < iMax; i++) {
				if (strstr(crew[i].company,
					AnsiString(EditSearchStr->Text).c_str()) != FALSE) {
					iCur++;
					Form1->ShowRecord();
					ListBox3->Items->Insert(a, Form1->EditCompany->Text + " " +
						Form1->EditAirbus->Text + " " +
						Form1->EditCountry->Text + " " + Form1->EditCity->Text +
						" " + Form1->EditCost->Text);
					a++;
				}
				else {
					iCur++;
					Form1->ShowRecord();
				}
			}
			break;
		}

	case 1: {
			for (int i = 0; i < iMax; i++) {
				if (strstr(crew[i].airbus,
					AnsiString(EditSearchStr->Text).c_str()) != FALSE) {
					iCur++;
					Form1->ShowRecord();
					ListBox3->Items->Insert(a, Form1->EditCompany->Text + " " +
						Form1->EditAirbus->Text + " " +
						Form1->EditCountry->Text + " " + Form1->EditCity->Text +
						" " + Form1->EditCost->Text);
					a++;
				}
				else {
					iCur++;
					Form1->ShowRecord();
				}
			}
			break;
		}
	case 2: {
			for (int i = 0; i < iMax; i++) {
				if (strstr(crew[i].country,
					AnsiString(EditSearchStr->Text).c_str()) != FALSE) {
					iCur++;
					Form1->ShowRecord();
					ListBox3->Items->Insert(a, Form1->EditCompany->Text + " " +
						Form1->EditAirbus->Text + " " +
						Form1->EditCountry->Text + " " + Form1->EditCity->Text +
						" " + Form1->EditCost->Text);
					a++;
				}
				else {
					iCur++;
					Form1->ShowRecord();
				}
			}
			break;
		}
	case 3: {
			for (int i = 0; i < iMax; i++) {
				if (strstr(crew[i].city,
					AnsiString(EditSearchStr->Text).c_str()) != FALSE) {
					iCur++;
					Form1->ShowRecord();
					ListBox3->Items->Insert(a, Form1->EditCompany->Text + " " +
						Form1->EditAirbus->Text + " " +
						Form1->EditCountry->Text + " " + Form1->EditCity->Text +
						" " + Form1->EditCost->Text);
					a++;
				}
				else {
					iCur++;
					Form1->ShowRecord();
				}
			}
			break;
		}
	case 4: {
			try {
				for (int i = 0; i < iMax; i++) {
					if (strstr(	AnsiString(crew[i].cost).c_str(),
						AnsiString(EditSearchStr->Text).c_str()) != FALSE) {
						iCur++;
						Form1->ShowRecord();
						ListBox3->Items->Insert(a,
							Form1->EditCompany->Text + " " +
							Form1->EditAirbus->Text + " " +
							Form1->EditCountry->Text + " " +
							Form1->EditCity->Text + " " +
							Form1->EditCost->Text);
						a++;
					}
					else {
						iCur++;
						Form1->ShowRecord();
					}

				}
			}
			catch (...) {
				ShowMessage("¬ведите число!");
			}
			break;
		}
	}
}
// ---------------------------------------------------------------------------

void __fastcall TForm2::RadioGroup1Click(TObject *Sender) {
	ListBox1->Items->Clear();
	iCur = -1;
	int a = 0;
	switch (RadioGroup1->ItemIndex) {
	case 0: {
			for (int i = 0; i < iMax; i++) {
				if (crew[i].company == EditFilter->Text) {
					iCur++;
					Form1->ShowRecord();
					ListBox1->Items->Insert(a, Form1->EditCompany->Text + " " +
						Form1->EditAirbus->Text + " " +
						Form1->EditCountry->Text + " " + Form1->EditCity->Text +
						" " + Form1->EditCost->Text);
					a++;
				}
				else {
					iCur++;
					Form1->ShowRecord();
				}
			}
			break;
		}

	case 1: {
			for (int i = 0; i < iMax; i++) {
				if (crew[i].airbus == EditFilter->Text) {
					iCur++;
					Form1->ShowRecord();
					ListBox1->Items->Insert(a, Form1->EditCompany->Text + " " +
						Form1->EditAirbus->Text + " " +
						Form1->EditCountry->Text + " " + Form1->EditCity->Text +
						" " + Form1->EditCost->Text);
					a++;
				}
				else {
					iCur++;
					Form1->ShowRecord();
				}
			}
			break;
		}
	case 2: {
			for (int i = 0; i < iMax; i++) {
				if (crew[i].country == EditFilter->Text) {
					iCur++;
					Form1->ShowRecord();
					ListBox1->Items->Insert(a, Form1->EditCompany->Text + " " +
						Form1->EditAirbus->Text + " " +
						Form1->EditCountry->Text + " " + Form1->EditCity->Text +
						" " + Form1->EditCost->Text);
					a++;
				}
				else {
					iCur++;
					Form1->ShowRecord();
				}
			}
			break;
		}
	case 3: {
			for (int i = 0; i < iMax; i++) {
				if (crew[i].city == EditFilter->Text) {
					iCur++;
					Form1->ShowRecord();
					ListBox1->Items->Insert(a, Form1->EditCompany->Text + " " +
						Form1->EditAirbus->Text + " " +
						Form1->EditCountry->Text + " " + Form1->EditCity->Text +
						" " + Form1->EditCost->Text);
					a++;
				}
				else {
					iCur++;
					Form1->ShowRecord();
				}
			}
			break;
		}
	case 4: {
			try {
				for (int i = 0; i < iMax; i++) {
					switch (RadioGroup2->ItemIndex) {
					case 0: {
							if (crew[i].cost < EditFilter->Text) {
								iCur++;
								Form1->ShowRecord();
								ListBox1->Items->Insert(a,
									Form1->EditCompany->Text + " " +
									Form1->EditAirbus->Text + " " +
									Form1->EditCountry->Text + " " +
									Form1->EditCity->Text + " " +
									Form1->EditCost->Text);
								a++;
							}
							else {
								iCur++;
								Form1->ShowRecord();
							}
							break;
						}
					case 1: {
							if (crew[i].cost > EditFilter->Text) {
								iCur++;
								Form1->ShowRecord();
								ListBox1->Items->Insert(a,
									Form1->EditCompany->Text + " " +
									Form1->EditAirbus->Text + " " +
									Form1->EditCountry->Text + " " +
									Form1->EditCity->Text + " " +
									Form1->EditCost->Text);
								a++;
							}
							else {
								iCur++;
								Form1->ShowRecord();
							}
							break;
						}
					}
				}
				break;
			}
			catch (...) {
				ShowMessage("¬ведите число!");
			}
		}

	}
}
// ---------------------------------------------------------------------------



void __fastcall TForm2::Exit1Click(TObject *Sender) {
	Form1->Close();
	Form2->Close();
}
// ---------------------------------------------------------------------------









