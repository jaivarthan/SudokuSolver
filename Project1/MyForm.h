#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <msclr\marshal_cppstd.h>	

#define SUDOKU_SIZE 9

int puzzle_a[SUDOKU_SIZE][SUDOKU_SIZE] = {};

namespace Project1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;
	
	
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::ProgressBar^ progressBar1;
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		/*******************************************************************
		*Function to check if any indivdual cell is filled/not filled 
		*in the Sudoku puzzle.
		/*******************************************************************/
		bool cell_unused(int &row,int &col)
		{
			/*Loop 9*9 matrix for any unfilled cell*/
			for (row = 0; row < SUDOKU_SIZE; row++)
			{
				for (col = 0; col < SUDOKU_SIZE; col++)
				{
					if (puzzle_a[row][col] == 0)
					{
						return true;
					}
				}
			}
			return false;
		}
		
		/*******************************************************************
		*Function to check if any indivdual cell in a row to
		*check duplicates.
		/*******************************************************************/
		bool RowCheck(int row, int num)
		{
			for (int col = 0; col < SUDOKU_SIZE; col++)
			{
				if (puzzle_a[row][col] == num)
				{
					return true;
				}
			}
			return false;
		}

		/*******************************************************************
		*Function to check if any indivdual cell in a column to
		*check duplicates.
		/*******************************************************************/
		bool ColumnCheck(int col, int num)
		{
			for (int row = 0; row < SUDOKU_SIZE; row++)
			{
				if (puzzle_a[row][col] == num)
				{
					return true;
				}
			}
			return false;
		}

		/*******************************************************************
		*Function to check in the 3*3 matrix tange to check for duplicates.
		/*******************************************************************/
		bool smallBoxCheck_3x3(int row_3x3,
			int col_3x3, int num)
		{
			/*Loop through the 3*3 box to check the number*/
			for (int row = 0; row < 3; row++)
			{
				for (int col = 0; col < 3; col++)
				{
					if (puzzle_a[row + row_3x3]
						[col + col_3x3] == num)
						return true;
				}
			}
			return false;
		}

		/*******************************************************************
		*Function to check the possibility of a temporary number to
		*fit in matrix as per the Sudoku puzzle rules.
		/*******************************************************************/
		bool sudokuCheck( int row,int col, int num)
		{
			if (puzzle_a[row][col] == 0)
			{
				/*Check in row,column & 3*3 matix for the number*/
				bool validNum = (!RowCheck(row, num) && !ColumnCheck(col, num)
					&& !smallBoxCheck_3x3(row - row % 3, col - col % 3, num));
				return validNum;
			}
			else
			{
				return false;
			}
		}
		/*******************************************************************
		*Function to clear the application display of dataGridview during 
		*new file loading & solved puzzle printing.
		/*******************************************************************/
		void deleteGrid()
		{
			int count = dataGridView1->RowCount - 2;
			while (dataGridView1->RowCount > 1)
			{
				dataGridView1->Rows->RemoveAt(count - 1);
				count = dataGridView1->RowCount - 1;
			}
			dataGridView1->RefreshEdit();
		}

		/*******************************************************************
		*Function to print the application display of dataGridview during 
		*new file loading & solved puzzle printing.
		/*******************************************************************/
		void printGrid()
		{
			for (int r = 0; r < SUDOKU_SIZE; r++)
			{
				DataGridViewRow^ row = gcnew DataGridViewRow();
				row->CreateCells(dataGridView1);

				for (int c = 0; c < SUDOKU_SIZE; c++) {
					if (puzzle_a[r][c] != 0)
					{
						row->Cells[c]->Value = puzzle_a[r][c];
					}
				}
				dataGridView1->Rows->Add(row);
				dataGridView1->Columns[r]->Width = 30;
			}
		}

		/*******************************************************************
		*Function to print the application display of dataGridview during
		*new file loading & solved puzzle printing.
		/*******************************************************************/
		bool Solve_puzzle()
		{
			int row, col;
			/*Check for any cells unfilled cells in matrix*/
			if (cell_unused(row, col) == false)
			{
				return true;
			}
			else
			{
				for (int num = 1; num <= 9; num++)
				{
					if (sudokuCheck(row, col, num))
					{
						puzzle_a[row][col] = num;
  
						if (Solve_puzzle())
						{
							return true;
						}
						puzzle_a[row][col] = 0;
					}
				}
				return false; 
			}
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::Windows::Forms::Button^ button1;
protected:

protected:

protected:

protected:

protected:

protected:

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

private: System::Windows::Forms::TextBox^ textBox1;




private: System::ComponentModel::IContainer^ components;


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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->openFileDialog2 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->button1->Location = System::Drawing::Point(450, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 44);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Choose File";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Silver;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F));
			this->button2->Location = System::Drawing::Point(450, 189);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 44);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Start";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			this->openFileDialog1->Filter = L"CSV Files|*.csv|All files (*.*)|*.*";
			this->openFileDialog1->Title = L"Select a CSV file";
			this->openFileDialog1->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm::openFileDialog1_FileOk);
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->ColumnHeadersVisible = false;
			this->dataGridView1->Enabled = false;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::Desktop;
			this->dataGridView1->Location = System::Drawing::Point(51, 37);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 20;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::RoyalBlue;
			dataGridViewCellStyle2->NullValue = nullptr;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::RoyalBlue;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->RowTemplate->Height = 3;
			this->dataGridView1->ScrollBars = System::Windows::Forms::ScrollBars::None;
			this->dataGridView1->Size = System::Drawing::Size(357, 252);
			this->dataGridView1->TabIndex = 2;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::Menu;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->ForeColor = System::Drawing::Color::Black;
			this->textBox1->Location = System::Drawing::Point(55, 301);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(226, 22);
			this->textBox1->TabIndex = 3;
			this->textBox1->UseWaitCursor = true;
			// 
			// progressBar1
			// 
			this->progressBar1->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->progressBar1->Cursor = System::Windows::Forms::Cursors::WaitCursor;
			this->progressBar1->Location = System::Drawing::Point(51, 325);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(357, 18);
			this->progressBar1->TabIndex = 4;
			this->progressBar1->UseWaitCursor = true;
			this->progressBar1->Visible = false;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(613, 365);
			this->Controls->Add(this->progressBar1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"Sudoku Solver";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		/*Local variables initialization*/
		bool err = false;
		using namespace std;
		static int index;
		index = 0;
		puzzle_a[9][9] = { 0 };
		int val[SUDOKU_SIZE * SUDOKU_SIZE];
		/*Browse file dialog to select a file to load*/
		String^ filename;
		openFileDialog1->InitialDirectory = "C:";
		openFileDialog1->Title = "Select a CSV file";
		openFileDialog1->ShowDialog();
		filename = openFileDialog1->SafeFileName;

		/*Filestream confguration to read the file*/
		FileStream^ fs = gcnew FileStream(openFileDialog1->FileName, FileMode::Open);
		StreamReader^ file1 = gcnew StreamReader(fs);
		String^ line;
		/*Application display settings,clear grid & progressbar*/
		progressBar1->Value = 0;
		progressBar1->Visible = false;
		DataGridView^ viewdata = gcnew DataGridView();
		dataGridView1->ColumnCount = SUDOKU_SIZE;
		deleteGrid();
		/*Read the file as string & convert it to integer with data check*/
		while (!file1->EndOfStream)
		{
			line = file1->ReadLine();
			/*Split the line string to indivdual array elements*/
			cli::array<System::String^>^ split = line->Split(',', '\n');
			for (int l = 0; l < split->Length; l++)
			{
				if (split[l] != "")
				{
					/*Remove white spaces*/
					split[l] = split[l]->Trim();
					try
					{
						/*Convert it to string & get in 1-D array*/
						val[index] = Convert::ToInt16(split[l]);
						index++;
					}
					catch (...)
					{
						/*Throw error if conversion is not possible*/
						err = true;
					}
				}
			}
		}
		/*Convert the 1-D array into 2-D array as per Sudoku rules*/
		for (int a = 0,point=0; a < SUDOKU_SIZE; a++)
		{
			for (int b = 0; b < SUDOKU_SIZE; b++)
			{
				if (val[point] >= 0 && val[point] <= SUDOKU_SIZE)
				{
					puzzle_a[a][b] = val[point];
					point++;
				}
				else
				{
					err = true;
				}
			}
		}
		/*Close file after data import*/
		fs->Close();

		if (err == false)
		{
			/*Display the data in application & enable Start button*/
			printGrid();
			button2->Enabled = true;
			textBox1->Text="File loaded! Press start to solve.";
		}
		else
		{
			/*Display error message & disable Start button*/
			MessageBox::Show("Invalid Input");
			textBox1->Text = "File loading unsuccessful.";
			button2->Enabled = false;
			return;
		}
	}
	
	private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
		int row_count = 1;
		auto begin = clock();			//Get time in ticks
		progressBar1->Value = 0;		//Initialize progressbar value
		progressBar1->Visible = true;	//Set progressbar visibility
		textBox1->Text = "Waiting";		
		/*Start the sudoku solving algorithm*/
		if (Solve_puzzle() == true)
		{
			/*Configure daatgrid view for display*/
			DataGridView^ viewdata = gcnew DataGridView();
			dataGridView1->ColumnCount = SUDOKU_SIZE;
			/*Clear datagridview with unsolved puzzle*/
			deleteGrid();
			progressBar1->Increment(25);
			/*Create output file for storing result*/
			String^ outputFile = openFileDialog1->FileName->Replace(".csv","_output.csv");
			FileStream^ fw = gcnew FileStream(outputFile, FileMode::Create);
			StreamWriter^ file1 = gcnew StreamWriter(fw);
			/*Display the data in application*/
			printGrid();
			progressBar1->Increment(50);
			/*Write data in output file as per CSV output format*/
			for (int r = 0; r < SUDOKU_SIZE; r++)
			{
				for (int c = 0; c < SUDOKU_SIZE; c++)
				{
					String^ a = puzzle_a[r][c].ToString();

					file1->Write(a);
					if (c+1 > 2  && c<8 && (c+1)% 3 == 0)
					{
						file1->Write("   ");
					}
					if (c >= 8)
					{
						file1->Write("\n");
					}
					else 
					{
						file1->Write(",");
					}

				}
				if (row_count >= 3)
				{
					file1->Write("\n");
					row_count = 0;
				}
				row_count++;
			}
			progressBar1->Increment(25);
			/*Close file after writing*/
			file1->Close(); 
			/*Get end time of clock*/
			auto end1 = clock();
			/*Calculate the time taken for solving the puzzle*/
			String^ time_ms = Convert::ToString(difftime(end1, begin));
			/*Print textbox messge with execution time*/
			textBox1->Text = "Finish!"+" Execution time: "+time_ms +"ms.";
		}
		else
		{
			/*If the sudoku cannot be solved*/
			MessageBox::Show("Input cannot be solved !!! ");
		}

	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void openFileDialog1_FileOk(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	}
};
}

