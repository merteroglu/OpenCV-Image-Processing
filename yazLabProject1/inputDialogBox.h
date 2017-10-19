#pragma once

namespace yazLabProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;




	/// <summary>
	/// Summary for inputDialogBox
	/// </summary>
	public ref class inputDialogBox : public System::Windows::Forms::Form
	{
	public:
		bool isOkey = false;
		int width = 0;
		int height = 0;

		inputDialogBox(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~inputDialogBox()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  txtBoxWidth;
	private: System::Windows::Forms::TextBox^  txtBoxHeight;
	protected:

	protected:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  btnOk;
	private: System::Windows::Forms::Button^  btnCancel;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->txtBoxWidth = (gcnew System::Windows::Forms::TextBox());
			this->txtBoxHeight = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// txtBoxWidth
			// 
			this->txtBoxWidth->Location = System::Drawing::Point(56, 8);
			this->txtBoxWidth->Name = L"txtBoxWidth";
			this->txtBoxWidth->Size = System::Drawing::Size(46, 20);
			this->txtBoxWidth->TabIndex = 0;
			// 
			// txtBoxHeight
			// 
			this->txtBoxHeight->Location = System::Drawing::Point(158, 9);
			this->txtBoxHeight->Name = L"txtBoxHeight";
			this->txtBoxHeight->Size = System::Drawing::Size(46, 20);
			this->txtBoxHeight->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(41, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Width :";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(108, 12);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(44, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Height :";
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(111, 44);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(93, 23);
			this->btnOk->TabIndex = 4;
			this->btnOk->Text = L"Resize";
			this->btnOk->UseVisualStyleBackColor = true;
			this->btnOk->Click += gcnew System::EventHandler(this, &inputDialogBox::btnOk_Click);
			// 
			// btnCancel
			// 
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(12, 44);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(93, 23);
			this->btnCancel->TabIndex = 5;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// inputDialogBox
			// 
			this->AcceptButton = this->btnOk;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->CancelButton = this->btnCancel;
			this->ClientSize = System::Drawing::Size(217, 85);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtBoxHeight);
			this->Controls->Add(this->txtBoxWidth);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"inputDialogBox";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Resize";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnOk_Click(System::Object^  sender, System::EventArgs^  e) {
		try {
			if (txtBoxWidth->TextLength != 0 && txtBoxHeight->TextLength != 0) {
				if (Convert::ToInt32(txtBoxWidth->Text) > 0 && Convert::ToInt32(txtBoxHeight->Text) > 0) {
					isOkey = true;
					width = Convert::ToInt32(txtBoxWidth->Text);
					height = Convert::ToInt32(txtBoxHeight->Text);
					Close();
				}
				else {
					// Show message
					MessageBox::Show("Yeni deðerler pozitif olmalýdýr", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
					
				}

			}
			else {
				// Show message
				MessageBox::Show("Deðerler boþ býrakýlamaz", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}catch(...){
			MessageBox::Show("Yalnýzca sayý girilebilir", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	public: System::Void setTextboxes(int w, int h) {
		txtBoxWidth->AppendText(w.ToString());
		txtBoxHeight->AppendText(h.ToString());
	}

};
}
