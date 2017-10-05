#pragma once

#include <opencv2\core\core.hpp>
#include <opencv2\highgui\highgui.hpp>
#include <string>
#include <msclr\marshal_cppstd.h>
#include "inputDialogBox.h"

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


	private: System::Windows::Forms::Button^  btnResize;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	private: System::Windows::Forms::Button^  btnCreateGrayHistogram;
	private: System::Windows::Forms::Button^  btnRGBHistogram;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnSave;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^  series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
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
			this->btnResize = (gcnew System::Windows::Forms::Button());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->btnCreateGrayHistogram = (gcnew System::Windows::Forms::Button());
			this->btnRGBHistogram = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->btnSave = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->groupBox1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
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
			this->pictureBox1->Location = System::Drawing::Point(3, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(334, 270);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->WaitOnLoad = true;
			// 
			// btnNegative
			// 
			this->btnNegative->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnNegative.Image")));
			this->btnNegative->Location = System::Drawing::Point(100, 23);
			this->btnNegative->Name = L"btnNegative";
			this->btnNegative->Size = System::Drawing::Size(39, 36);
			this->btnNegative->TabIndex = 2;
			this->btnNegative->UseVisualStyleBackColor = true;
			this->btnNegative->Click += gcnew System::EventHandler(this, &MainForm::btnNegative_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(767, 35);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"label1";
			this->label1->Click += gcnew System::EventHandler(this, &MainForm::label1_Click);
			// 
			// btnSagAynala
			// 
			this->btnSagAynala->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSagAynala.Image")));
			this->btnSagAynala->Location = System::Drawing::Point(145, 23);
			this->btnSagAynala->Name = L"btnSagAynala";
			this->btnSagAynala->Size = System::Drawing::Size(39, 36);
			this->btnSagAynala->TabIndex = 4;
			this->btnSagAynala->UseVisualStyleBackColor = true;
			this->btnSagAynala->Click += gcnew System::EventHandler(this, &MainForm::btnSagAynala_Click);
			// 
			// btnSagaDondur
			// 
			this->btnSagaDondur->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSagaDondur.Image")));
			this->btnSagaDondur->Location = System::Drawing::Point(190, 23);
			this->btnSagaDondur->Name = L"btnSagaDondur";
			this->btnSagaDondur->Size = System::Drawing::Size(39, 36);
			this->btnSagaDondur->TabIndex = 5;
			this->btnSagaDondur->UseVisualStyleBackColor = true;
			this->btnSagaDondur->Click += gcnew System::EventHandler(this, &MainForm::btnSagaDondur_Click);
			// 
			// btnSolaDondur
			// 
			this->btnSolaDondur->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSolaDondur.Image")));
			this->btnSolaDondur->Location = System::Drawing::Point(235, 23);
			this->btnSolaDondur->Name = L"btnSolaDondur";
			this->btnSolaDondur->Size = System::Drawing::Size(39, 36);
			this->btnSolaDondur->TabIndex = 6;
			this->btnSolaDondur->UseVisualStyleBackColor = true;
			this->btnSolaDondur->Click += gcnew System::EventHandler(this, &MainForm::btnSolaDondur_Click);
			// 
			// btnGriTonlama
			// 
			this->btnGriTonlama->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnGriTonlama.Image")));
			this->btnGriTonlama->Location = System::Drawing::Point(280, 23);
			this->btnGriTonlama->Name = L"btnGriTonlama";
			this->btnGriTonlama->Size = System::Drawing::Size(39, 36);
			this->btnGriTonlama->TabIndex = 7;
			this->btnGriTonlama->UseVisualStyleBackColor = true;
			this->btnGriTonlama->Click += gcnew System::EventHandler(this, &MainForm::btnGriTonlama_Click);
			// 
			// btnReOpen
			// 
			this->btnReOpen->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnReOpen.Image")));
			this->btnReOpen->Location = System::Drawing::Point(325, 23);
			this->btnReOpen->Name = L"btnReOpen";
			this->btnReOpen->Size = System::Drawing::Size(39, 36);
			this->btnReOpen->TabIndex = 8;
			this->btnReOpen->UseVisualStyleBackColor = true;
			this->btnReOpen->Click += gcnew System::EventHandler(this, &MainForm::btnReOpen_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->rButtonOrjinal);
			this->groupBox1->Controls->Add(this->rButtonBlue);
			this->groupBox1->Controls->Add(this->rButtonGreen);
			this->groupBox1->Controls->Add(this->rButtonRed);
			this->groupBox1->Location = System::Drawing::Point(503, 19);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(236, 50);
			this->groupBox1->TabIndex = 10;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Renk Kanallarý";
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
			// btnResize
			// 
			this->btnResize->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnResize.Image")));
			this->btnResize->Location = System::Drawing::Point(459, 23);
			this->btnResize->Margin = System::Windows::Forms::Padding(2);
			this->btnResize->Name = L"btnResize";
			this->btnResize->Size = System::Drawing::Size(39, 36);
			this->btnResize->TabIndex = 13;
			this->btnResize->UseVisualStyleBackColor = true;
			this->btnResize->Click += gcnew System::EventHandler(this, &MainForm::btnResize_Click);
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(296, 92);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->IsXValueIndexed = true;
			series1->Legend = L"Legend1";
			series1->Name = L"Histogram";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series2->IsXValueIndexed = true;
			series2->Legend = L"Legend1";
			series2->Name = L"Red";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series3->IsXValueIndexed = true;
			series3->Legend = L"Legend1";
			series3->Name = L"Blue";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series4->IsXValueIndexed = true;
			series4->Legend = L"Legend1";
			series4->Name = L"Green";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Series->Add(series3);
			this->chart1->Series->Add(series4);
			this->chart1->Size = System::Drawing::Size(387, 128);
			this->chart1->TabIndex = 11;
			this->chart1->Text = L"chart1";
			this->chart1->Visible = false;
			// 
			// btnCreateGrayHistogram
			// 
			this->btnCreateGrayHistogram->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnCreateGrayHistogram.Image")));
			this->btnCreateGrayHistogram->Location = System::Drawing::Point(370, 23);
			this->btnCreateGrayHistogram->Name = L"btnCreateGrayHistogram";
			this->btnCreateGrayHistogram->Size = System::Drawing::Size(39, 36);
			this->btnCreateGrayHistogram->TabIndex = 14;
			this->btnCreateGrayHistogram->UseVisualStyleBackColor = true;
			this->btnCreateGrayHistogram->Click += gcnew System::EventHandler(this, &MainForm::btnCreateGrayHistogram_Click);
			// 
			// btnRGBHistogram
			// 
			this->btnRGBHistogram->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnRGBHistogram.Image")));
			this->btnRGBHistogram->Location = System::Drawing::Point(415, 23);
			this->btnRGBHistogram->Name = L"btnRGBHistogram";
			this->btnRGBHistogram->Size = System::Drawing::Size(39, 36);
			this->btnRGBHistogram->TabIndex = 15;
			this->btnRGBHistogram->UseVisualStyleBackColor = true;
			this->btnRGBHistogram->Click += gcnew System::EventHandler(this, &MainForm::btnRGBHistogram_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->btnSave);
			this->groupBox2->Controls->Add(this->btnOpen);
			this->groupBox2->Controls->Add(this->btnRGBHistogram);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->groupBox1);
			this->groupBox2->Controls->Add(this->btnResize);
			this->groupBox2->Controls->Add(this->btnNegative);
			this->groupBox2->Controls->Add(this->btnCreateGrayHistogram);
			this->groupBox2->Controls->Add(this->btnSagAynala);
			this->groupBox2->Controls->Add(this->btnSagaDondur);
			this->groupBox2->Controls->Add(this->btnSolaDondur);
			this->groupBox2->Controls->Add(this->btnGriTonlama);
			this->groupBox2->Controls->Add(this->btnReOpen);
			this->groupBox2->Location = System::Drawing::Point(2, 3);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1350, 83);
			this->groupBox2->TabIndex = 16;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Menu";
			// 
			// btnSave
			// 
			this->btnSave->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"btnSave.Image")));
			this->btnSave->Location = System::Drawing::Point(55, 23);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(39, 36);
			this->btnSave->TabIndex = 16;
			this->btnSave->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->AutoScroll = true;
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Location = System::Drawing::Point(12, 92);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1350, 650);
			this->panel1->TabIndex = 17;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(1025, 578);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void btnOpen_Click(System::Object^  sender, System::EventArgs^  e) {
		
		
		openFileDialog1->Filter = "Image Files |*.*|Jpg |*.jpg|Png |*.png|Jpeg |*.jpeg";
		openFileDialog1->Title = "Resim Dosyasýný seçiniz";

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
			pictureBox1->BackgroundImage = System::Drawing::Image::FromFile(managed);
			pictureBox1->BackgroundImageLayout = ImageLayout::Stretch;
		}



		if (img.empty()) {
			MessageBox::Show("Resim Açýlamadý", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
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
		
		if (img.empty())
			return;

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
		 if (img.empty())
			 return;

		 try {
			 System::Drawing::Graphics^ graphics = control->CreateGraphics();
			 System::IntPtr ptr(colorImage.ptr());
			 System::Drawing::Bitmap^ b = gcnew System::Drawing::Bitmap(colorImage.cols, colorImage.rows, colorImage.step, System::Drawing::Imaging::PixelFormat::Format24bppRgb, ptr);
			 System::Drawing::RectangleF rect(0, 0, control->Width, control->Height);
			 graphics->DrawImage(b, rect);
			 delete graphics;
		 }
		 catch(System::Exception ^e){
			// MessageBox::Show("Resim Gösterilemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		 }

		
	 }




private: System::Void btnSagaDondur_Click(System::Object^  sender, System::EventArgs^  e) {

	if (img.empty())
		return;

	cv::Size newSize =  cv::Size(img.size().height, img.size().width);
	Mat transpozeImg = Mat::zeros(newSize, img.type());
	Mat dondurulenImg = Mat::zeros(newSize, img.type());
	int i, j;

		
	try {
		for (i = 0; i < img.rows; i++) {
			for (j = 0; j < img.cols; j++) {
				dondurulenImg.at<cv::Vec3b>(j, i) = img.at<cv::Vec3b>(img.rows - i-1, j);
			}
		}

		img = dondurulenImg;
		tempImg = img;
		pictureBox1->Width = img.size().width;
		pictureBox1->Height = img.size().height;

		//imshow("dondurulen", dondurulenImg);
		DrawCVImage(pictureBox1, img);

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
		label1->Text = " i ve j :" + i.ToString() + " , " + j.ToString();
		img = dondurulenImg;
		tempImg = img;
		pictureBox1->Width = img.size().width;
		pictureBox1->Height = img.size().height;

		DrawCVImage(pictureBox1, img);
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
		DrawCVImage(pictureBox1, newImg);
	}
	catch(System::Exception ^e){
		MessageBox::Show("Gri Tonlama Yapýlamadý", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void btnReOpen_Click(System::Object^  sender, System::EventArgs^  e) {

	if (path == NULL)
		return;

	img = imread(path);
	tempImg = img;
	pictureBox1->Width = img.size().width;
	pictureBox1->Height = img.size().height;
	System::String ^ managed = openFileDialog1->FileName;
	pictureBox1->BackgroundImage = System::Drawing::Image::FromFile(managed);
	pictureBox1->BackgroundImageLayout = ImageLayout::Stretch;
	rButtonOrjinal->Checked = true;
}

void setRGBChannels(int type) {
	if (img.empty())
		return;

	try {
		Mat newImg = Mat::zeros(img.size(), img.type());
		img = tempImg;
		for (int i = 0; i < img.rows; i++) {
			for (int j = 0; j < img.cols; j++) {
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
	catch (System::Exception ^e) {
		MessageBox::Show("RGB Kanallarý deðiþtirilemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
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
private: System::Void btnResize_Click(System::Object^  sender, System::EventArgs^  e) {

	if (img.empty())
		return;

	inputDialogBox ^ form = gcnew inputDialogBox;

	form->ShowDialog();

	int newWidth, newHeight;

	if (form->isOkey) {
		newHeight = form->width;
		newWidth = form->height;
		

		try {
			cv::Size newSize = cv::Size(newHeight, newWidth);

			Mat newImg = Mat::zeros(newSize, img.type());

			int imgX, imgY;

			for (int i = 0; i <newHeight; i++) {
				for (int j = 0; j <newWidth; j++) {

					imgX = (int)(round(((float)i) / (float)newWidth * (float)img.cols));
					imgY = (int)(round(((float)j) / (float)newHeight * (float)img.rows));
					imgX = min(imgX, img.cols - 1);
					imgY = min(imgY, img.rows - 1);

					cv::Vec3b myVec = img.at<cv::Vec3b>(imgY, imgX);
					uchar tempR = myVec[2];
					uchar tempG = myVec[1];
					uchar tempB = myVec[0];
					cv::Vec3b newPoint(tempB, tempG, tempR);
					newImg.at<cv::Vec3b>(j, i) = newPoint;

				}
			}
			img = newImg;
			tempImg = img;
			pictureBox1->Width = img.size().width;
			pictureBox1->Height = img.size().height;
			DrawCVImage(pictureBox1, img);
		}
		catch (System::Exception ^e) {
			MessageBox::Show("Boyut deðiþtirilemedi", "Hata", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

}

private: System::Void btnCreateGrayHistogram_Click(System::Object^  sender, System::EventArgs^  e) {
	int arr[256] = { 0 };
	this->chart1->Series["Red"]->Points->Clear();
	this->chart1->Series["Blue"]->Points->Clear();
	this->chart1->Series["Green"]->Points->Clear();
	this->chart1->Series["Histogram"]->Points->Clear();

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			arr[(int)img.at<uchar>(i, j)]++;
		}
	}

	for (int k = 0; k < 256; k++) {
		this->chart1->Series["Histogram"]->Points->AddXY(k, arr[k]);
	}

}


private: System::Void btnRGBHistogram_Click(System::Object^  sender, System::EventArgs^  e) {
	this->chart1->Series["Red"]->Points->Clear();
	this->chart1->Series["Blue"]->Points->Clear();
	this->chart1->Series["Green"]->Points->Clear();
	this->chart1->Series["Histogram"]->Points->Clear();

	int arrR[256] = { 0 };
	int arrB[256] = { 0 };
	int arrG[256] = { 0 };

	for (int i = 0; i < img.rows; i++) {
		for (int j = 0; j < img.cols; j++) {
			cv::Vec3b myVec = img.at<cv::Vec3b>(i, j);
			uchar tempR = myVec[2];
			uchar tempG = myVec[1];
			uchar tempB = myVec[0];
			arrR[(int)tempR]++;
			arrB[(int)tempB]++;
			arrG[(int)tempG]++;

		}
	}

	for (int k = 0; k < 256; k++) {
		this->chart1->Series["Red"]->Points->AddXY(k, arrR[k]);
		this->chart1->Series["Blue"]->Points->AddXY(k, arrB[k]);
		this->chart1->Series["Green"]->Points->AddXY(k, arrG[k]);
	}
}

};


}
