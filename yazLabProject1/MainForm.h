#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "inputDialogBox.h"
#include "inputChannels.h"
#include "formHistogram.h"
#define histSize 20

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
	int histStep = 0;
	Mat historyImgs[histSize];

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
			pictureBox1->BackgroundImageLayout = ImageLayout::Stretch;
			toolTip1->SetToolTip(btnOpen, "Open");
			toolTip1->SetToolTip(btnSave, "Save");
			toolTip1->SetToolTip(btnNegative, "Negative");
			toolTip1->SetToolTip(btnSagAynala, "Horizontal Mirroring");
			toolTip1->SetToolTip(btnSagaDondur, "Right rotate");
			toolTip1->SetToolTip(btnSolaDondur, "Left rotate");
			toolTip1->SetToolTip(btnGriTonlama, "Grayscale");
			toolTip1->SetToolTip(btnReOpen, "Reopen");
			toolTip1->SetToolTip(btnCreateGrayHistogram, "Gray Histogram");
			toolTip1->SetToolTip(btnRGBHistogram, "RGB Histogram");
			toolTip1->SetToolTip(btnResize, "Resize");
			toolTip1->SetToolTip(btnChangeChannels, "Change RGB Channels");

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







	private: System::Windows::Forms::Button^  btnResize;

	private: System::Windows::Forms::Button^  btnCreateGrayHistogram;
	private: System::Windows::Forms::Button^  btnRGBHistogram;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnSave;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  btnChangeChannels;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::Button^  btnUndo;
	private: System::Windows::Forms::Button^  btnDikeyAynala;
	private: System::ComponentModel::IContainer^  components;




	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
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
			this->btnResize = (gcnew System::Windows::Forms::Button());
			this->btnCreateGrayHistogram = (gcnew System::Windows::Forms::Button());
			this->btnRGBHistogram = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btnDikeyAynala = (gcnew System::Windows::Forms::Button());
			this->btnUndo = (gcnew System::Windows::Forms::Button());
			this->btnChangeChannels = (gcnew System::Windows::Forms::Button());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnOpen
			// 
			this->btnOpen->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnOpen.Image")));
			this->btnOpen->Location = System::Drawing::Point(10, 23);
			this->btnOpen->Name = L"btnOpen";
			this->btnOpen->Size = System::Drawing::Size(39, 36);
			this->btnOpen->TabIndex = 0;
			this->btnOpen->UseVisualStyleBackColor = true;
			this->btnOpen->Click += gcnew System::EventHandler(this, &MainForm::btnOpen_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(334, 270);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->WaitOnLoad = true;
			// 
			// btnNegative
			// 
			this->btnNegative->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNegative.Image")));
			this->btnNegative->Location = System::Drawing::Point(144, 23);
			this->btnNegative->Name = L"btnNegative";
			this->btnNegative->Size = System::Drawing::Size(39, 36);
			this->btnNegative->TabIndex = 2;
			this->btnNegative->UseVisualStyleBackColor = true;
			this->btnNegative->Click += gcnew System::EventHandler(this, &MainForm::btnNegative_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(770, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			this->label1->Visible = false;
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// btnSagAynala
			// 
			this->btnSagAynala->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSagAynala.Image")));
			this->btnSagAynala->Location = System::Drawing::Point(189, 23);
			this->btnSagAynala->Name = L"btnSagAynala";
			this->btnSagAynala->Size = System::Drawing::Size(39, 36);
			this->btnSagAynala->TabIndex = 4;
			this->btnSagAynala->UseVisualStyleBackColor = true;
			this->btnSagAynala->Click += gcnew System::EventHandler(this, &MainForm::btnSagAynala_Click);
			// 
			// btnSagaDondur
			// 
			this->btnSagaDondur->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSagaDondur.Image")));
			this->btnSagaDondur->Location = System::Drawing::Point(279, 23);
			this->btnSagaDondur->Name = L"btnSagaDondur";
			this->btnSagaDondur->Size = System::Drawing::Size(39, 36);
			this->btnSagaDondur->TabIndex = 5;
			this->btnSagaDondur->UseVisualStyleBackColor = true;
			this->btnSagaDondur->Click += gcnew System::EventHandler(this, &MainForm::btnSagaDondur_Click);
			// 
			// btnSolaDondur
			// 
			this->btnSolaDondur->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSolaDondur.Image")));
			this->btnSolaDondur->Location = System::Drawing::Point(324, 23);
			this->btnSolaDondur->Name = L"btnSolaDondur";
			this->btnSolaDondur->Size = System::Drawing::Size(39, 36);
			this->btnSolaDondur->TabIndex = 6;
			this->btnSolaDondur->UseVisualStyleBackColor = true;
			this->btnSolaDondur->Click += gcnew System::EventHandler(this, &MainForm::btnSolaDondur_Click);
			// 
			// btnGriTonlama
			// 
			this->btnGriTonlama->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGriTonlama.Image")));
			this->btnGriTonlama->Location = System::Drawing::Point(369, 23);
			this->btnGriTonlama->Name = L"btnGriTonlama";
			this->btnGriTonlama->Size = System::Drawing::Size(39, 36);
			this->btnGriTonlama->TabIndex = 7;
			this->btnGriTonlama->UseVisualStyleBackColor = true;
			this->btnGriTonlama->Click += gcnew System::EventHandler(this, &MainForm::btnGriTonlama_Click);
			// 
			// btnReOpen
			// 
			this->btnReOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnReOpen.Image")));
			this->btnReOpen->Location = System::Drawing::Point(414, 23);
			this->btnReOpen->Name = L"btnReOpen";
			this->btnReOpen->Size = System::Drawing::Size(39, 36);
			this->btnReOpen->TabIndex = 8;
			this->btnReOpen->UseVisualStyleBackColor = true;
			this->btnReOpen->Click += gcnew System::EventHandler(this, &MainForm::btnReOpen_Click);
			// 
			// btnResize
			// 
			this->btnResize->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnResize.Image")));
			this->btnResize->Location = System::Drawing::Point(458, 23);
			this->btnResize->Margin = System::Windows::Forms::Padding(2);
			this->btnResize->Name = L"btnResize";
			this->btnResize->Size = System::Drawing::Size(39, 36);
			this->btnResize->TabIndex = 13;
			this->btnResize->UseVisualStyleBackColor = true;
			this->btnResize->Click += gcnew System::EventHandler(this, &MainForm::btnResize_Click);
			// 
			// btnCreateGrayHistogram
			// 
			this->btnCreateGrayHistogram->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreateGrayHistogram.Image")));
			this->btnCreateGrayHistogram->Location = System::Drawing::Point(546, 23);
			this->btnCreateGrayHistogram->Name = L"btnCreateGrayHistogram";
			this->btnCreateGrayHistogram->Size = System::Drawing::Size(39, 36);
			this->btnCreateGrayHistogram->TabIndex = 14;
			this->btnCreateGrayHistogram->UseVisualStyleBackColor = true;
			this->btnCreateGrayHistogram->Click += gcnew System::EventHandler(this, &MainForm::btnCreateGrayHistogram_Click);
			// 
			// btnRGBHistogram
			// 
			this->btnRGBHistogram->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRGBHistogram.Image")));
			this->btnRGBHistogram->Location = System::Drawing::Point(591, 23);
			this->btnRGBHistogram->Name = L"btnRGBHistogram";
			this->btnRGBHistogram->Size = System::Drawing::Size(39, 36);
			this->btnRGBHistogram->TabIndex = 15;
			this->btnRGBHistogram->UseVisualStyleBackColor = true;
			this->btnRGBHistogram->Click += gcnew System::EventHandler(this, &MainForm::btnRGBHistogram_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->btnDikeyAynala);
			this->groupBox2->Controls->Add(this->btnUndo);
			this->groupBox2->Controls->Add(this->btnChangeChannels);
			this->groupBox2->Controls->Add(this->btnSave);
			this->groupBox2->Controls->Add(this->btnOpen);
			this->groupBox2->Controls->Add(this->btnRGBHistogram);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->btnResize);
			this->groupBox2->Controls->Add(this->btnNegative);
			this->groupBox2->Controls->Add(this->btnCreateGrayHistogram);
			this->groupBox2->Controls->Add(this->btnSagAynala);
			this->groupBox2->Controls->Add(this->btnSagaDondur);
			this->groupBox2->Controls->Add(this->btnSolaDondur);
			this->groupBox2->Controls->Add(this->btnGriTonlama);
			this->groupBox2->Controls->Add(this->btnReOpen);
			this->groupBox2->Location = System::Drawing::Point(12, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1340, 83);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Menu";
			// 
			// btnDikeyAynala
			// 
			this->btnDikeyAynala->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnDikeyAynala.BackgroundImage")));
			this->btnDikeyAynala->Location = System::Drawing::Point(234, 23);
			this->btnDikeyAynala->Name = L"btnDikeyAynala";
			this->btnDikeyAynala->Size = System::Drawing::Size(39, 36);
			this->btnDikeyAynala->TabIndex = 19;
			this->toolTip1->SetToolTip(this->btnDikeyAynala, L"Vertical Mirroring");
			this->btnDikeyAynala->UseVisualStyleBackColor = true;
			this->btnDikeyAynala->Click += gcnew System::EventHandler(this, &MainForm::btnDikeyAynala_Click);
			// 
			// btnUndo
			// 
			this->btnUndo->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnUndo.BackgroundImage")));
			this->btnUndo->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnUndo->Enabled = false;
			this->btnUndo->Location = System::Drawing::Point(100, 23);
			this->btnUndo->Name = L"btnUndo";
			this->btnUndo->Size = System::Drawing::Size(38, 36);
			this->btnUndo->TabIndex = 18;
			this->toolTip1->SetToolTip(this->btnUndo, L"Undo");
			this->btnUndo->UseVisualStyleBackColor = true;
			this->btnUndo->Click += gcnew System::EventHandler(this, &MainForm::btnUndo_Click);
			// 
			// btnChangeChannels
			// 
			this->btnChangeChannels->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnChangeChannels.Image")));
			this->btnChangeChannels->Location = System::Drawing::Point(502, 23);
			this->btnChangeChannels->Name = L"btnChangeChannels";
			this->btnChangeChannels->Size = System::Drawing::Size(38, 36);
			this->btnChangeChannels->TabIndex = 17;
			this->btnChangeChannels->UseVisualStyleBackColor = true;
			this->btnChangeChannels->Click += gcnew System::EventHandler(this, &MainForm::btnChangeChannels_Click);
			// 
			// btnSave
			// 
			this->btnSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSave.Image")));
			this->btnSave->Location = System::Drawing::Point(55, 23);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(39, 36);
			this->btnSave->TabIndex = 16;
			this->btnSave->UseVisualStyleBackColor = true;
			this->btnSave->Click += gcnew System::EventHandler(this, &MainForm::btnSave_Click);
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(12, 92);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1340, 620);
			this->panel1->TabIndex = 17;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1143, 700);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox2);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MainForm";
			this->Text = L"Imageshop - YazLab Proje 1";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {

		openFileDialog1->Filter = "Image Files |*.*|Jpg |*.jpg|Png |*.png|Jpeg |*.jpeg";
		openFileDialog1->Title = "Resim Dosyasını seçiniz";
		try {
			if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
				//MessageBox::Show(openFileDialog1->FileName, "Path");
				System::String ^ managed = openFileDialog1->FileName;
				std::string str = msclr::interop::marshal_as<std::string>(managed);
				path = str;
				img = imread(str);
				tempImg = img;
				pictureBox1->Width = img.size().width;
				pictureBox1->Height = img.size().height;
				//pictureBox1->Load(managed);
				//pictureBox1->BackgroundImage = System::Drawing::Image::FromFile(managed);
				//DrawCVImage(pictureBox1, img);
				MatToPictureBox(img);
				addToHistory(img);
			}
		}
		catch (...) {
			MessageBox::Show("Resim Açılamadı", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		

		if (img.empty()) {
			MessageBox::Show("Resim Açılamadı", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
		
		if (img.empty())
			return;

		Mat negativeImg = Mat::zeros(img.size(), img.type());

		/*
		Mat negativeImg = Mat::zeros(img.size(), img.type());
		Mat sub_mat = Mat::ones(img.size(), img.type()) * 255;
		
		subtract(sub_mat, img, negativeImg);
		*/

		try {
			for (int i = 0; i < img.rows; i++) {
				for (int j = 0; j < img.cols; j++) {
					cv::Vec3b myVec = img.at<cv::Vec3b>(i, j);
					cv::Vec3b newPoint(255 - myVec[0], 255 - myVec[1], 255 - myVec[2]);
					negativeImg.at<cv::Vec3b>(i, j) = newPoint;
				}
			}

			img = negativeImg;
			tempImg = img;
			//imshow("Negative image", negativeImg);
			//DrawCVImage(pictureBox1, negativeImg);
			MatToPictureBox(img);
			addToHistory(img);
		}
		catch (...) {
			MessageBox::Show("Negatif işlemi yapılamadı", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		
		
	}

    private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	
	}

    private: System::Void btnSagAynala_Click(System::Object^  sender, System::EventArgs^  e) {
		
		if (img.empty())
			return;

		try {
			Mat aynalananImg = Mat::zeros(img.size(), img.type());
			int i, j;

			for (i = 0; i < img.rows; i++) {
				for (j = 0; j < img.cols; j++) {
					aynalananImg.at<cv::Vec3b>(i, img.cols - j - 1) = img.at<cv::Vec3b>(i, j);
				}
			}

			img = aynalananImg;
			tempImg = img;

			//DrawCVImage(pictureBox1, img);
			MatToPictureBox(img);
			addToHistory(img);
			//imshow("Aynalama",aynalananImg);
		}
		catch (...) {
			MessageBox::Show("Aynalama işlemi yapılamadı", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

   }


	 void DrawCVImage(System::Windows::Forms::Control^ control, cv::Mat& colorImage) {

		 if (img.empty())
			 return;
		 /*
		 try {
			 System::Drawing::Graphics^ graphics = control->CreateGraphics();
			 System::IntPtr ptr(colorImage.ptr());
			 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);

 			 System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
			 graphics->DrawImage(b, rect);
			 delete graphics;
		 }
		 catch(...){
			 MessageBox::Show("Resim Gösterilemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		 } */
		 try {
			 
			// pictureBox1->BackgroundImage = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step,
				// System::Drawing::Imaging::PixelFormat::Format24bppRgb, (System::IntPtr)colorImage.ptr());
			 Mat gray;
			 cv::cvtColor(colorImage, gray, CV_BGR2GRAY, 1);
			 colorImage = gray;
			 System::IntPtr ptr(colorImage.ptr());
				pictureBox1->Image = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step  ,
				 System::Drawing::Imaging::PixelFormat::Format8bppIndexed, ptr);
			 pictureBox1->Refresh();
		 }
		 catch (System::ArgumentException^ e) {
			 MessageBox::Show(e->ToString(), "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		 }
		
	 }

	 void MatToPictureBox(const cv::Mat& img) {
		 if (img.type() != CV_8UC3) {
			 MessageBox::Show("Desteklenmeyen format","Hata" ,MessageBoxButtons::OK, MessageBoxIcon::Error);
			 return;
		 }
		

		 System::Drawing::Imaging::PixelFormat fmt ( System::Drawing::Imaging::PixelFormat::Format24bppRgb);
		 
		 Bitmap ^bmpimg = gcnew Bitmap(img.cols, img.rows, fmt);

		 System::Drawing::Imaging::BitmapData ^data = bmpimg->LockBits(System::Drawing::Rectangle(0, 0, img.cols, img.rows), System::Drawing::Imaging::ImageLockMode::WriteOnly, fmt);

		 byte *dstData = reinterpret_cast<byte*>(data->Scan0.ToPointer());

		 unsigned char *srcData = img.data;

		 for (int row = 0; row < data->Height; row++) {
			 memcpy(reinterpret_cast<void*>(&dstData[row*data->Stride]), reinterpret_cast<void*>(&srcData[row*img.step]), img.cols*img.channels());
		 }

		 bmpimg->UnlockBits(data);

		 pictureBox1->Image = bmpimg;
		 pictureBox1->Refresh();

	 }

	 void DrawImageBox(System::Windows::Forms::Control^ control, cv::Mat& colorImage) {

		 if (img.empty())
			 return;
		 
		 try {
		 
		 System::Drawing::Graphics^ graphics = pictureBox1->CreateGraphics();
		 System::IntPtr ptr(colorImage.ptr());
		 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);

		 System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
		 graphics->DrawImage(b, rect);
		 pictureBox1->Refresh();
		 delete graphics;
		 }
		 catch(...){
		// MessageBox::Show("Resim Gösterilemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		 } 

	 }

    

private: System::Void btnSagaDondur_Click(System::Object^  sender, System::EventArgs^  e) {

	if (img.empty())
		return;
	
	try {
		cv::Size newSize = cv::Size(img.size().height, img.size().width);
		Mat dondurulenImg = Mat::zeros(newSize, img.type());
		int i, j;

		for (i = 0; i < img.rows; i++) {
			for (j = 0; j < img.cols; j++) {
				dondurulenImg.at<cv::Vec3b>(j, i) = img.at<cv::Vec3b>(img.rows - i-1, j);
				
			}
		}

		img = dondurulenImg;
		tempImg = img;

		//imshow("dondurulen", img);
		//pictureBox1->Width = img.cols;
		//pictureBox1->Height = img.rows;
		//DrawCVImage(pictureBox1, img);
		MatToPictureBox(img);
		addToHistory(img);
	}
	catch (System::Exception^ e) {
		MessageBox::Show("Resim Döndürülemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}

private: System::Void btnSolaDondur_Click(System::Object^  sender, System::EventArgs^  e) {

	if (img.empty())
		return;

	cv::Size newSize = cv::Size(img.size().height, img.size().width);
	Mat dondurulenImg = Mat::zeros(newSize, img.type());
	int i, j;

	try {
		for (i = 0; i < img.rows; i++) {
			for (j = 0; j < img.cols; j++) {
				dondurulenImg.at<cv::Vec3b>(img.cols - j - 1, i) = img.at<cv::Vec3b>(i, j);
			}
		}
		img = dondurulenImg;
		tempImg = img;
		//pictureBox1->Width = img.size().width;
		//pictureBox1->Height = img.size().height;
		//DrawCVImage(pictureBox1, img);
		MatToPictureBox(img);
		addToHistory(img);
	}
	catch (System::Exception ^e) {
		MessageBox::Show("Resim Döndürülemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}

private: System::Void btnGriTonlama_Click(System::Object^  sender, System::EventArgs^  e) {

	if (img.empty())
		return;

	try {
		Mat newImg = Mat::zeros(img.size(), img.type());
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
		//DrawCVImage(pictureBox1, newImg);
		MatToPictureBox(img);
		addToHistory(img);
	}
	catch(System::Exception ^e){
		MessageBox::Show("Gri Tonlama Yapılamadı", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnReOpen_Click(System::Object^  sender, System::EventArgs^  e) {

	if (path == "")
		return;

	img = imread(path);
	tempImg = img;
	MatToPictureBox(img);
	addToHistory(img);
	//DrawCVImage(pictureBox1, img);
	//pictureBox1->Width = img.size().width;
	//pictureBox1->Height = img.size().height;
	
	//System::String ^ managed = openFileDialog1->FileName;
	//pictureBox1->BackgroundImage = System::Drawing::Image::FromFile(managed);
	
}

void setRGBChannels(int type) {

	if (img.empty())
		return;

	try {
		Mat newImg = Mat::zeros(img.size(), img.type());
		img = tempImg;
		if(type != 3){
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				cv::Vec3b myVec = img.at<cv::Vec3b>(i, j);
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
				cv::Vec3b newPoint(tempB, tempG, tempR);
				newImg.at<cv::Vec3b>(i, j) = newPoint;
			}
		  }
			img = newImg;
		}
		else {
			img = tempImg;
		}
		
		//DrawCVImage(pictureBox1, newImg);
		MatToPictureBox(img);
		addToHistory(img);
	}
	catch (System::Exception ^e) {
		MessageBox::Show("RGB Kanalları değiştirilemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

void setRGBChannels2(int type) {

	if (img.empty())
		return;

	try {
		Mat newImg = Mat::zeros(img.size(), img.type());
		img = tempImg;
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				cv::Vec3b myVec = img.at<cv::Vec3b>(i, j);
				uchar tempR = myVec[2];
				uchar tempG = myVec[1];
				uchar tempB = myVec[0];
				if (type == 0) {
					cv::Vec3b newPoint(tempR, tempR, tempR);
					newImg.at<cv::Vec3b>(i, j) = newPoint;
				}
				else if (type == 1) {
					cv::Vec3b newPoint(tempG, tempG, tempG);
					newImg.at<cv::Vec3b>(i, j) = newPoint;
				}
				else if (type == 2) {
					cv::Vec3b newPoint(tempB, tempB, tempB);
					newImg.at<cv::Vec3b>(i, j) = newPoint;
				}
				else if (type == 3) {
					newImg = tempImg;
				}
				
				
			}
		}
		img = newImg;
	    MatToPictureBox(img);
		addToHistory(img);
	}
	catch (System::Exception ^e) {
		MessageBox::Show("RGB Kanalları değiştirilemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}


private: System::Void btnResize_Click(System::Object^  sender, System::EventArgs^  e) {

	if (img.empty())
		return;

	inputDialogBox ^ form = gcnew inputDialogBox;

	form->setTextboxes(img.cols, img.rows);

	form->ShowDialog();

	int newWidth, newHeight;

	if (form->isOkey) {
		 newWidth = form->width;
		 newHeight = form->height;
		
		try {
			cv::Size newSize = cv::Size(newWidth, newHeight);
			
			Mat newImg = Mat::zeros(newSize, img.type());

		
			int imgX, imgY;

			for (int i = 0; i <newHeight; i++) {
				for (int j = 0; j <newWidth; j++) {

					imgX = (int)(round(((float)j) / (float)newWidth * (float)img.cols));
					imgY = (int)(round(((float)i) / (float)newHeight * (float)img.rows));
					imgX = min(imgX, img.cols - 1);
					imgY = min(imgY, img.rows - 1);

					cv::Vec3b myVec = img.at<cv::Vec3b>(imgY, imgX);
					uchar tempR = myVec[2];
					uchar tempG = myVec[1];
					uchar tempB = myVec[0];
					cv::Vec3b newPoint(tempB, tempG, tempR);
					newImg.at<cv::Vec3b>(i, j) = newPoint;
				}
			}
			//imshow("resized", newImg);
			img = newImg.clone();
			tempImg = img.clone();
			MatToPictureBox(img);
			addToHistory(img);
			//DrawCVImage(pictureBox1, img);
			//imshow("resized image", img);
			
		}
		catch (System::Exception ^e) {
			MessageBox::Show("Boyut değiştirilemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
}

private: System::Void btnCreateGrayHistogram_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (img.empty())
		return;

	formHistogram^ form = gcnew formHistogram;

	form->Text = "Gray image Histogram";
	
	int arr[256] = { 0 };
	
	try {
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				arr[(int)img.at<uchar>(i, j)]++;
			}
		}
	}
	catch (...) {
		MessageBox::Show("Histogram oluşturulamadı", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	form->chartDoldur(arr);
	form->Show();
}


private: System::Void btnRGBHistogram_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (img.empty())
		return;

	formHistogram^ form = gcnew formHistogram;
	
	form->Text = "RGB Histogram";

	int varLuma[256] = { 0 };

	try {
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
				cv::Vec3b myVec = img.at<cv::Vec3b>(i, j);
				uchar tempR = myVec[2];
				uchar tempG = myVec[1];
				uchar tempB = myVec[0];
				// VarLuma = 0.299²⋅VarRed + 0.587²⋅VarGreen + 0.114²⋅VarBlue
				// (0.0894f * (int)tempR) + (0.3445f * (int)tempG) + (0.0129f *(int)tempB);
				//int val = (0.089401f * (int)tempR) + (0.344569f * (int)tempG) + (0.012996f *(int)tempB);
				int val = (0.2126f * (int)tempR) + (0.7152f * (int)tempG) + (0.0722f *(int)tempB);
				varLuma[val]++;
			}
		}
	}
	catch (...) {
		MessageBox::Show("Histogram oluşturulamadı", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	form->chartDoldur(varLuma);

	form->Show();

}

private: System::Void btnSave_Click(System::Object^  sender, System::EventArgs^  e) {

	if (img.empty())
		return;

	saveFileDialog1->Filter = "Jpeg|*.jpeg|Jpg|*.jpg|Png|*.png";
	saveFileDialog1->Title = "Save image";
	saveFileDialog1->ShowDialog();
	try {
		if (saveFileDialog1->FileName != "") {
			System::String ^ managed = saveFileDialog1->FileName;
			std::string str = msclr::interop::marshal_as<std::string>(managed);

			imwrite(str, img);
			MessageBox::Show("Resim kayıt edildi", "Kayıt Başarılı", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
	}
	catch (...) {
		MessageBox::Show("Resim kaydedilemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

	
}

private: System::Void btnChangeChannels_Click(System::Object^  sender, System::EventArgs^  e) {
	
	if (img.empty())
		return;

	inputChannels ^ form = gcnew inputChannels;

	form->ShowDialog();

	if (form->isOk) {
		setRGBChannels2(form->select);
	}

}

private: void addToHistory(Mat img){
	if (histStep < histSize) {
		historyImgs[histStep] = img;
		histStep++;
	}
	else {
		for (int i = 1; i < histSize; i++) {
			historyImgs[i - 1] = historyImgs[i];
		}
		historyImgs[histStep] = img;
	}

	if (histStep > 1 && btnUndo->Enabled == false) {
		btnUndo->Enabled = true;
	}
}

private: void undo() {
	if (histStep > 1) {
		histStep--;
		img = historyImgs[histStep - 1];
		tempImg = img;
		MatToPictureBox(img);
		if (histStep == 1) {
			btnUndo->Enabled = false;
		}
	}
}


private: System::Void btnUndo_Click(System::Object^  sender, System::EventArgs^  e) {
	undo();
}

private: System::Void btnDikeyAynala_Click(System::Object^  sender, System::EventArgs^  e) {
	if (img.empty())
		return;

	try {
		Mat aynalananImg = Mat::zeros(img.size(), img.type());
		int i, j;

		for (i = 0; i < img.rows; i++) {
			for (j = 0; j < img.cols; j++) {
				aynalananImg.at<cv::Vec3b>(img.rows-i-1, j) = img.at<cv::Vec3b>(i, j);
			}
		}

		img = aynalananImg;
		tempImg = img;

		//DrawCVImage(pictureBox1, img);
		MatToPictureBox(img);
		addToHistory(img);
		//imshow("Aynalama",aynalananImg);
	}
	catch (...) {
		MessageBox::Show("Aynalama işlemi yapılamadı", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}

}

};

}
