#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <string>
#include <msclr\marshal_cppstd.h>

namespace yazLabProject1 {

   

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace cv;
	using namespace msclr::interop;
    
	Mat img,tempImg;
	std::string path;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
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
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  btnOpen;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  btnNegative;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  btnSagAynala;
	private: System::Windows::Forms::Button^  btnSagaDondur;
	private: System::Windows::Forms::Button^  btnSolaDondur;
	private: System::Windows::Forms::Button^  btnGriTonlama;
	private: System::Windows::Forms::Button^  btnReOpen;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  rButtonOrjinal;
	private: System::Windows::Forms::RadioButton^  rButtonBlue;
	private: System::Windows::Forms::RadioButton^  rButtonGreen;
	private: System::Windows::Forms::RadioButton^  rButtonRed;

	protected:

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
			this->btnOpen = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnNegative = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnSagAynala = (gcnew System::Windows::Forms::Button());
			this->btnSagaDondur = (gcnew System::Windows::Forms::Button());
			this->btnSolaDondur = (gcnew System::Windows::Forms::Button());
			this->btnGriTonlama = (gcnew System::Windows::Forms::Button());
			this->btnReOpen = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->rButtonOrjinal = (gcnew System::Windows::Forms::RadioButton());
			this->rButtonBlue = (gcnew System::Windows::Forms::RadioButton());
			this->rButtonGreen = (gcnew System::Windows::Forms::RadioButton());
			this->rButtonRed = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnOpen
			// 
			this->btnOpen->Location = System::Drawing::Point(609, 12);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(101, 23);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->Text = L"Resim A�";
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MainForm::btnOpen_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(512, 512);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// btnNegative
			// 
			this->btnNegative->Location = System::Drawing::Point(609, 41);
			this->btnNegative->Name = L"btnNegative";
			this->btnNegative->Size = System::Drawing::Size(101, 23);
			this->btnNegative->TabIndex = 2;
			this->btnNegative->Text = L"Negative/Invert";
			this->btnNegative->UseVisualStyleBackColor = true;
			this->btnNegative->Click += gcnew System::EventHandler(this, &MainForm::btnNegative_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(560, 305);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// btnSagAynala
			// 
			this->btnSagAynala->Location = System::Drawing::Point(609, 71);
			this->btnSagAynala->Name = L"btnSagAynala";
			this->btnSagAynala->Size = System::Drawing::Size(101, 23);
			this->btnSagAynala->TabIndex = 4;
			this->btnSagAynala->Text = L"Aynala";
			this->btnSagAynala->UseVisualStyleBackColor = true;
			this->btnSagAynala->Click += gcnew System::EventHandler(this, &MainForm::btnSagAynala_Click);
			// 
			// btnSagaDondur
			// 
			this->btnSagaDondur->Location = System::Drawing::Point(609, 100);
			this->btnSagaDondur->Name = L"btnSagaDondur";
			this->btnSagaDondur->Size = System::Drawing::Size(101, 23);
			this->btnSagaDondur->TabIndex = 5;
			this->btnSagaDondur->Text = L"90 Derece Sa�a";
			this->btnSagaDondur->UseVisualStyleBackColor = true;
			this->btnSagaDondur->Click += gcnew System::EventHandler(this, &MainForm::btnSagaDondur_Click);
			// 
			// btnSolaDondur
			// 
			this->btnSolaDondur->Location = System::Drawing::Point(609, 130);
			this->btnSolaDondur->Name = L"btnSolaDondur";
			this->btnSolaDondur->Size = System::Drawing::Size(101, 23);
			this->btnSolaDondur->TabIndex = 6;
			this->btnSolaDondur->Text = L"90 Derece Sola";
			this->btnSolaDondur->UseVisualStyleBackColor = true;
			this->btnSolaDondur->Click += gcnew System::EventHandler(this, &MainForm::btnSolaDondur_Click);
			// 
			// btnGriTonlama
			// 
			this->btnGriTonlama->Location = System::Drawing::Point(609, 160);
			this->btnGriTonlama->Name = L"btnGriTonlama";
			this->btnGriTonlama->Size = System::Drawing::Size(101, 23);
			this->btnGriTonlama->TabIndex = 7;
			this->btnGriTonlama->Text = L"Gri Tonlama";
			this->btnGriTonlama->UseVisualStyleBackColor = true;
			this->btnGriTonlama->Click += gcnew System::EventHandler(this, &MainForm::btnGriTonlama_Click);
			// 
			// btnReOpen
			// 
			this->btnReOpen->Location = System::Drawing::Point(609, 190);
			this->btnReOpen->Name = L"btnReOpen";
			this->btnReOpen->Size = System::Drawing::Size(101, 23);
			this->btnReOpen->TabIndex = 8;
			this->btnReOpen->Text = L"Tekrar A�";
			this->btnReOpen->UseVisualStyleBackColor = true;
			this->btnReOpen->Click += gcnew System::EventHandler(this, &MainForm::btnReOpen_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rButtonOrjinal);
			this->groupBox1->Controls->Add(this->rButtonBlue);
			this->groupBox1->Controls->Add(this->rButtonGreen);
			this->groupBox1->Controls->Add(this->rButtonRed);
			this->groupBox1->Location = System::Drawing::Point(563, 219);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(236, 50);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Renk Kanallar�";
			// 
			// rButtonOrjinal
			// 
			this->rButtonOrjinal->AutoSize = true;
			this->rButtonOrjinal->Checked = true;
			this->rButtonOrjinal->Location = System::Drawing::Point(171, 19);
			this->rButtonOrjinal->Name = L"rButtonOrjinal";
			this->rButtonOrjinal->Size = System::Drawing::Size(54, 17);
			this->rButtonOrjinal->TabIndex = 3;
			this->rButtonOrjinal->TabStop = true;
			this->rButtonOrjinal->Text = L"Orjinal";
			this->rButtonOrjinal->UseVisualStyleBackColor = true;
			this->rButtonOrjinal->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rButtonOrjinal_CheckedChanged);
			// 
			// rButtonBlue
			// 
			this->rButtonBlue->AutoSize = true;
			this->rButtonBlue->Location = System::Drawing::Point(118, 19);
			this->rButtonBlue->Name = L"rButtonBlue";
			this->rButtonBlue->Size = System::Drawing::Size(46, 17);
			this->rButtonBlue->TabIndex = 2;
			this->rButtonBlue->Text = L"Blue";
			this->rButtonBlue->UseVisualStyleBackColor = true;
			this->rButtonBlue->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rButtonBlue_CheckedChanged);
			// 
			// rButtonGreen
			// 
			this->rButtonGreen->AutoSize = true;
			this->rButtonGreen->Location = System::Drawing::Point(58, 19);
			this->rButtonGreen->Name = L"rButtonGreen";
			this->rButtonGreen->Size = System::Drawing::Size(54, 17);
			this->rButtonGreen->TabIndex = 1;
			this->rButtonGreen->Text = L"Green";
			this->rButtonGreen->UseVisualStyleBackColor = true;
			this->rButtonGreen->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rButtonGreen_CheckedChanged);
			// 
			// rButtonRed
			// 
			this->rButtonRed->AutoSize = true;
			this->rButtonRed->Location = System::Drawing::Point(6, 19);
			this->rButtonRed->Name = L"rButtonRed";
			this->rButtonRed->Size = System::Drawing::Size(45, 17);
			this->rButtonRed->TabIndex = 0;
			this->rButtonRed->Text = L"Red";
			this->rButtonRed->UseVisualStyleBackColor = true;
			this->rButtonRed->CheckedChanged += gcnew System::EventHandler(this, &MainForm::rButtonRed_CheckedChanged);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1008, 561);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->btnReOpen);
			this->Controls->Add(this->btnGriTonlama);
			this->Controls->Add(this->btnSolaDondur);
			this->Controls->Add(this->btnSagaDondur);
			this->Controls->Add(this->btnSagAynala);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->btnNegative);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->btnOpen);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
		openFileDialog1->Filter = "Image Files|*.*|*.jpg|*.png|*.jpeg|";
		openFileDialog1->Title = "Resim Dosyas�n� se�iniz";

		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//MessageBox::Show(openFileDialog1->FileName, "Path");
			System::String ^ managed = openFileDialog1->FileName;
			std::string str = msclr::interop::marshal_as<std::string>(managed);
			path = str;
			img = imread(str);
			tempImg = img;
			//pictureBox1->Load(managed);
			pictureBox1->BackgroundImage = System::Drawing::Image::FromFile(managed);
			pictureBox1->BackgroundImageLayout = ImageLayout::Stretch;
		}



		if (img.empty()) {
			MessageBox::Show("Resim A��lamad�", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		else {
		/*	namedWindow("Resim Gosterme", CV_WINDOW_AUTOSIZE);
			imshow("Resim Gosterme", img);
			waitKey(0);
			destroyWindow("Resim Gosterme");
		*/
		}

	}
	
    private: System::Void btnNegative_Click(System::Object^  sender, System::EventArgs^  e) {
		
		Mat negativeImg = Mat::zeros(img.size(), img.type());

		label1->Text = "image rows:" + img.rows.ToString() + " image cols:" + img.cols.ToString() + " image size :" + img.size().width + "," + img.size().height;		

		/*
		Mat negativeImg = Mat::zeros(img.size(), img.type());
		Mat sub_mat = Mat::ones(img.size(), img.type()) * 255;
		
		subtract(sub_mat, img, negativeImg);
		*/

		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				cv::Vec3b myVec = img.at<cv::Vec3b>(i, j);
				cv::Vec3b newPoint(255-myVec[0], 255 - myVec[1], 255 - myVec[2]);
				negativeImg.at<cv::Vec3b>(i, j) = newPoint;
			}
		}

		img = negativeImg;
		tempImg = img;
		//imshow("Negative image", negativeImg);

		DrawCVImage(pictureBox1, negativeImg);
		waitKey(0);
	}

    private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
}

    private: System::Void btnSagAynala_Click(System::Object^  sender, System::EventArgs^  e) {
		
		Mat aynalananImg = Mat::zeros(img.size(), img.type());
		int i,j;
		
		for (i = 0; i < img.rows; i++) {
			for (j = 0; j < img.cols; j++) {
				aynalananImg.at<cv::Vec3b>(i, img.cols - j - 1) = img.at<cv::Vec3b>(i, j);
			}
		}
		
		

		label1->Text = " i ve j :" + i.ToString() + " , " + j.ToString();
		img = aynalananImg;
		tempImg = img;

		DrawCVImage(pictureBox1, img);

		//imshow("Aynalama",aynalananImg);

    }


	 void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage) {
		 System::Drawing::Graphics^ graphics = control->CreateGraphics();
		 System::IntPtr ptr(colorImage.ptr());
		 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
		 System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
		 graphics->DrawImage(b, rect);
		 delete graphics;
	 }




private: System::Void btnSagaDondur_Click(System::Object^  sender, System::EventArgs^  e) {
	cv::Size newSize =  cv::Size(img.size().height, img.size().width);
	Mat transpozeImg = Mat::zeros(newSize, img.type());
	Mat dondurulenImg = Mat::zeros(newSize, img.type());
	int i, j;

	label1->Text = " w ve h :" + img.rows.ToString() + " , " + img.cols.ToString();
		
		for (i = 0; i < img.rows; i++) {
			for (j = 0; j < img.cols; j++) {
				dondurulenImg.at<cv::Vec3b>(j, i) = img.at<cv::Vec3b>(img.rows - i-1, j);
			}
		}
	
	
			//label1->Text = " i ve j :" + i.ToString() + " , " + j.ToString();
	img = dondurulenImg;
	tempImg = img;
			//imshow("dondurulen", dondurulenImg);
	DrawCVImage(pictureBox1, img);

}


private: System::Void btnSolaDondur_Click(System::Object^  sender, System::EventArgs^  e) {
	cv::Size newSize = cv::Size(img.size().height, img.size().width);
	Mat dondurulenImg = Mat::zeros(newSize, img.type());
	int i, j;

	for (i = 0; i < img.rows; i++) {
		for (j = 0; j < img.cols; j++) {
			//dondurulenImg.at<cv::Vec3b>(j,i) = img.at<cv::Vec3b>(i, img.cols - j - 1);
			dondurulenImg.at<cv::Vec3b>(img.cols - j - 1, i) = img.at<cv::Vec3b>(i, j);
		}
	}

	label1->Text = " i ve j :" + i.ToString() + " , " + j.ToString();
	img = dondurulenImg;
	tempImg = img;
	//imshow("dondurulen", img);
	DrawCVImage(pictureBox1, img);
}



private: System::Void btnGriTonlama_Click(System::Object^  sender, System::EventArgs^  e) {
	Mat newImg = Mat::zeros(img.size(), img.type());

	//Mat C = (Mat_<double>(3, 3) << 0.412453, 0.357580, 0.180423, 0.212671, 0.715160, 0.072169, 0.019334, 0.119193, 0.950227);

	int i, j;

	for (i = 0; i < img.rows; i++) {
		for (j = 0; j < img.cols; j++) {
			cv::Vec3b myVec = img.at<cv::Vec3b>(i, j);
			uchar temp = (myVec[0] + myVec[1] + myVec[2]) / 3;
			cv::Vec3b newPoint(temp, temp, temp);
			newImg.at<cv::Vec3b>(i, j) = newPoint;
		}
	}
	
	img = newImg;
	tempImg = img;
	//imshow("dondurulen", img);
	DrawCVImage(pictureBox1, newImg);
}

private: System::Void btnReOpen_Click(System::Object^  sender, System::EventArgs^  e) {
	img = imread(path);
	tempImg = img;
	//pictureBox1->Load(managed);
	System::String ^ managed = openFileDialog1->FileName;
	pictureBox1->BackgroundImage = System::Drawing::Image::FromFile(managed);
	pictureBox1->BackgroundImageLayout = ImageLayout::Stretch;

}

void setRGBChannels(int type) {
	Mat newImg = Mat::zeros(img.size(), img.type());
	img = tempImg;
	int i, j;

	for (i = 0; i < img.rows; i++) {
		for (j = 0; j < img.cols; j++) {
			cv::Vec3b myVec = img.at<cv::Vec3b>(i, j);
			//uchar temp = (myVec[0] + myVec[1] + myVec[2]) / 3;
			uchar tempR = myVec[2];
			uchar tempG = myVec[1];
			uchar tempB = myVec[0];
			if (type == 0) {
				tempR = 255;
			}
			else if (type == 1) {
				tempG = 255;
			}
			else if (type == 2) {
				tempB = 255;
			}
			else if (type == 3) {
				img = tempImg;
			}

			cv::Vec3b newPoint(tempB, tempG, tempR);
			newImg.at<cv::Vec3b>(i, j) = newPoint;
		}
	}
	img = newImg;
	DrawCVImage(pictureBox1, newImg);


}


private: System::Void rButtonRed_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (rButtonRed->Checked) {
		setRGBChannels(0);
	}
}

private: System::Void rButtonGreen_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (rButtonGreen->Checked) {
		setRGBChannels(1);
	}
}
private: System::Void rButtonBlue_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (rButtonBlue->Checked) {
		setRGBChannels(2);
	}
}
private: System::Void rButtonOrjinal_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	if (rButtonOrjinal->Checked) {
		setRGBChannels(3);
	}
}
};


}
