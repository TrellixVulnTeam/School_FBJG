#pragma once

namespace Ticketgenerator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Souhrn pro MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Sem přidejte kód konstruktoru.
			//
		}

	protected:
		/// <summary>
		/// Uvolněte všechny používané prostředky.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  id;
	private: System::Windows::Forms::Label^  label;
	protected:

	private: System::Windows::Forms::TextBox^  type;

	private: System::Windows::Forms::TextBox^  name;
	private: System::Windows::Forms::Button^  plus;
	private: System::Windows::Forms::Button^  minus;
	private: System::Windows::Forms::Button^  print;
	private: System::Windows::Forms::PictureBox^  qr;
	private: System::Windows::Forms::PrintDialog^  printDialog;
	private: System::Drawing::Printing::PrintDocument^  printDocumentTicket;


	private: System::Windows::Forms::PrintPreviewDialog^  printPreviewDialog;
	private: System::Windows::Forms::Timer^  timer;
	private: System::Windows::Forms::Panel^  Ticket;
	private: System::Windows::Forms::Panel^  Menu;
	private: System::Windows::Forms::Button^  menuBtn;

	private: System::Windows::Forms::Button^  pricetagBtn;

	private: System::Windows::Forms::Button^  ticketBtn;
	private: System::Windows::Forms::Panel^  mainPanel;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  idFrom;
	private: System::Windows::Forms::PictureBox^  pictureBox1;

	private: System::Windows::Forms::Panel^  Pricetag;
	private: System::Windows::Forms::Label^  Line;
	private: System::Windows::Forms::Button^  PrintPricetag;

	private: System::Windows::Forms::TextBox^  FoodNameText;
	private: System::Windows::Forms::TextBox^  PriceText;
	private: System::Windows::Forms::Button^  optionsBtn;
	private: System::Windows::Forms::PictureBox^  LogoPriceTag;


	private: System::Drawing::Printing::PrintDocument^  printDocumentPricetag;
	private: System::Windows::Forms::Button^  foodLabelBtn;
	private: System::Windows::Forms::Panel^  FoodLabel;
	private: System::Windows::Forms::Button^  printFoodLabel;
	private: System::Windows::Forms::TextBox^  nameFoodLabelText;
	private: System::Windows::Forms::Label^  expLabel;





	private: System::Windows::Forms::Label^  manLabel;
	private: System::Windows::Forms::DateTimePicker^  expDate;
	private: System::Windows::Forms::DateTimePicker^  manDate;
	private: System::Windows::Forms::PictureBox^  LogoFoodLabel;

	private: System::Windows::Forms::Panel^  Options;
	private: System::Windows::Forms::Button^  cancelBtn;
	private: System::Windows::Forms::Button^  saveBtn;
	private: System::Windows::Forms::ImageList^  Icons;
	private: System::Windows::Forms::ImageList^  Logos;
	private: System::Drawing::Printing::PrintDocument^  printDocumentFoodLabel;










	private: System::ComponentModel::IContainer^  components;

			 			 					  		   		   		  
	private:
		/// <summary>
		/// Vyžaduje se proměnná návrháře.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Metoda vyžadovaná pro podporu Návrháře - neupravovat
		/// obsah této metody v editoru kódu.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->id = (gcnew System::Windows::Forms::TextBox());
			this->label = (gcnew System::Windows::Forms::Label());
			this->type = (gcnew System::Windows::Forms::TextBox());
			this->name = (gcnew System::Windows::Forms::TextBox());
			this->plus = (gcnew System::Windows::Forms::Button());
			this->minus = (gcnew System::Windows::Forms::Button());
			this->print = (gcnew System::Windows::Forms::Button());
			this->qr = (gcnew System::Windows::Forms::PictureBox());
			this->printDialog = (gcnew System::Windows::Forms::PrintDialog());
			this->printDocumentTicket = (gcnew System::Drawing::Printing::PrintDocument());
			this->printPreviewDialog = (gcnew System::Windows::Forms::PrintPreviewDialog());
			this->timer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Ticket = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->idFrom = (gcnew System::Windows::Forms::TextBox());
			this->Menu = (gcnew System::Windows::Forms::Panel());
			this->optionsBtn = (gcnew System::Windows::Forms::Button());
			this->foodLabelBtn = (gcnew System::Windows::Forms::Button());
			this->pricetagBtn = (gcnew System::Windows::Forms::Button());
			this->ticketBtn = (gcnew System::Windows::Forms::Button());
			this->menuBtn = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->mainPanel = (gcnew System::Windows::Forms::Panel());
			this->FoodLabel = (gcnew System::Windows::Forms::Panel());
			this->expLabel = (gcnew System::Windows::Forms::Label());
			this->manLabel = (gcnew System::Windows::Forms::Label());
			this->expDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->manDate = (gcnew System::Windows::Forms::DateTimePicker());
			this->printFoodLabel = (gcnew System::Windows::Forms::Button());
			this->nameFoodLabelText = (gcnew System::Windows::Forms::TextBox());
			this->LogoFoodLabel = (gcnew System::Windows::Forms::PictureBox());
			this->Pricetag = (gcnew System::Windows::Forms::Panel());
			this->FoodNameText = (gcnew System::Windows::Forms::TextBox());
			this->LogoPriceTag = (gcnew System::Windows::Forms::PictureBox());
			this->Line = (gcnew System::Windows::Forms::Label());
			this->PrintPricetag = (gcnew System::Windows::Forms::Button());
			this->PriceText = (gcnew System::Windows::Forms::TextBox());
			this->Options = (gcnew System::Windows::Forms::Panel());
			this->saveBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->printDocumentPricetag = (gcnew System::Drawing::Printing::PrintDocument());
			this->Icons = (gcnew System::Windows::Forms::ImageList(this->components));
			this->Logos = (gcnew System::Windows::Forms::ImageList(this->components));
			this->printDocumentFoodLabel = (gcnew System::Drawing::Printing::PrintDocument());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->qr))->BeginInit();
			this->Ticket->SuspendLayout();
			this->Menu->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->mainPanel->SuspendLayout();
			this->FoodLabel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoFoodLabel))->BeginInit();
			this->Pricetag->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPriceTag))->BeginInit();
			this->Options->SuspendLayout();
			this->SuspendLayout();
			// 
			// id
			// 
			resources->ApplyResources(this->id, L"id");
			this->id->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->id->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->id->Name = L"id";
			this->id->Enter += gcnew System::EventHandler(this, &MyForm::id_Enter);
			this->id->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::id_KeyPress);
			this->id->Leave += gcnew System::EventHandler(this, &MyForm::id_Leave);
			// 
			// label
			// 
			resources->ApplyResources(this->label, L"label");
			this->label->Name = L"label";
			// 
			// type
			// 
			resources->ApplyResources(this->type, L"type");
			this->type->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->type->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->type->Name = L"type";
			this->type->Enter += gcnew System::EventHandler(this, &MyForm::type_Enter);
			this->type->Leave += gcnew System::EventHandler(this, &MyForm::type_Leave);
			// 
			// name
			// 
			resources->ApplyResources(this->name, L"name");
			this->name->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->name->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->name->Name = L"name";
			this->name->Enter += gcnew System::EventHandler(this, &MyForm::name_Enter);
			this->name->Leave += gcnew System::EventHandler(this, &MyForm::name_Leave);
			// 
			// plus
			// 
			resources->ApplyResources(this->plus, L"plus");
			this->plus->BackColor = System::Drawing::Color::Black;
			this->plus->FlatAppearance->BorderSize = 0;
			this->plus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->plus->Name = L"plus";
			this->plus->TabStop = false;
			this->plus->UseVisualStyleBackColor = false;
			this->plus->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::plus_MouseDown);
			this->plus->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::plus_MouseUp);
			// 
			// minus
			// 
			resources->ApplyResources(this->minus, L"minus");
			this->minus->BackColor = System::Drawing::Color::Black;
			this->minus->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->minus->FlatAppearance->BorderSize = 0;
			this->minus->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->minus->ForeColor = System::Drawing::Color::White;
			this->minus->Name = L"minus";
			this->minus->TabStop = false;
			this->minus->UseVisualStyleBackColor = false;
			this->minus->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::minus_MouseDown);
			this->minus->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::minus_MouseUp);
			// 
			// print
			// 
			resources->ApplyResources(this->print, L"print");
			this->print->BackColor = System::Drawing::Color::Black;
			this->print->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->print->FlatAppearance->BorderSize = 0;
			this->print->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->print->ForeColor = System::Drawing::Color::White;
			this->print->Name = L"print";
			this->print->UseVisualStyleBackColor = false;
			this->print->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::print_MouseClick);
			// 
			// qr
			// 
			resources->ApplyResources(this->qr, L"qr");
			this->qr->Name = L"qr";
			this->qr->TabStop = false;
			// 
			// printDialog
			// 
			this->printDialog->UseEXDialog = true;
			// 
			// printDocumentTicket
			// 
			this->printDocumentTicket->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MyForm::printDocumentTicket_PrintPage);
			// 
			// printPreviewDialog
			// 
			resources->ApplyResources(this->printPreviewDialog, L"printPreviewDialog");
			this->printPreviewDialog->Name = L"printPreviewDialog1";
			// 
			// timer
			// 
			this->timer->Interval = 80;
			this->timer->Tick += gcnew System::EventHandler(this, &MyForm::timer_Tick);
			// 
			// Ticket
			// 
			resources->ApplyResources(this->Ticket, L"Ticket");
			this->Ticket->BackColor = System::Drawing::Color::White;
			this->Ticket->Controls->Add(this->label1);
			this->Ticket->Controls->Add(this->idFrom);
			this->Ticket->Controls->Add(this->label);
			this->Ticket->Controls->Add(this->minus);
			this->Ticket->Controls->Add(this->id);
			this->Ticket->Controls->Add(this->print);
			this->Ticket->Controls->Add(this->plus);
			this->Ticket->Controls->Add(this->qr);
			this->Ticket->Controls->Add(this->name);
			this->Ticket->Controls->Add(this->type);
			this->Ticket->Name = L"Ticket";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// idFrom
			// 
			resources->ApplyResources(this->idFrom, L"idFrom");
			this->idFrom->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->idFrom->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->idFrom->Name = L"idFrom";
			this->idFrom->Enter += gcnew System::EventHandler(this, &MyForm::idFrom_Enter);
			this->idFrom->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::idFrom_KeyPress);
			this->idFrom->Leave += gcnew System::EventHandler(this, &MyForm::idFrom_Leave);
			// 
			// Menu
			// 
			resources->ApplyResources(this->Menu, L"Menu");
			this->Menu->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->Menu->Controls->Add(this->optionsBtn);
			this->Menu->Controls->Add(this->foodLabelBtn);
			this->Menu->Controls->Add(this->pricetagBtn);
			this->Menu->Controls->Add(this->ticketBtn);
			this->Menu->Controls->Add(this->menuBtn);
			this->Menu->Controls->Add(this->pictureBox1);
			this->Menu->Name = L"Menu";
			// 
			// optionsBtn
			// 
			resources->ApplyResources(this->optionsBtn, L"optionsBtn");
			this->optionsBtn->FlatAppearance->BorderSize = 0;
			this->optionsBtn->ForeColor = System::Drawing::Color::White;
			this->optionsBtn->Name = L"optionsBtn";
			this->optionsBtn->UseVisualStyleBackColor = true;
			this->optionsBtn->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::OptionsBtn_MouseUp);
			// 
			// foodLabelBtn
			// 
			resources->ApplyResources(this->foodLabelBtn, L"foodLabelBtn");
			this->foodLabelBtn->FlatAppearance->BorderSize = 0;
			this->foodLabelBtn->ForeColor = System::Drawing::Color::White;
			this->foodLabelBtn->Name = L"foodLabelBtn";
			this->foodLabelBtn->UseVisualStyleBackColor = true;
			this->foodLabelBtn->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::foodLabelBtn_MouseUp);
			// 
			// pricetagBtn
			// 
			resources->ApplyResources(this->pricetagBtn, L"pricetagBtn");
			this->pricetagBtn->FlatAppearance->BorderSize = 0;
			this->pricetagBtn->ForeColor = System::Drawing::Color::White;
			this->pricetagBtn->Name = L"pricetagBtn";
			this->pricetagBtn->UseVisualStyleBackColor = true;
			this->pricetagBtn->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pricetagBtn_MouseUp);
			// 
			// ticketBtn
			// 
			resources->ApplyResources(this->ticketBtn, L"ticketBtn");
			this->ticketBtn->BackColor = System::Drawing::Color::RoyalBlue;
			this->ticketBtn->FlatAppearance->BorderSize = 0;
			this->ticketBtn->ForeColor = System::Drawing::Color::White;
			this->ticketBtn->Name = L"ticketBtn";
			this->ticketBtn->UseVisualStyleBackColor = false;
			this->ticketBtn->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::ticketBtn_MouseUp);
			// 
			// menuBtn
			// 
			resources->ApplyResources(this->menuBtn, L"menuBtn");
			this->menuBtn->FlatAppearance->BorderSize = 0;
			this->menuBtn->ForeColor = System::Drawing::Color::White;
			this->menuBtn->Name = L"menuBtn";
			this->menuBtn->UseVisualStyleBackColor = true;
			this->menuBtn->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::menuBtn_MouseUp);
			// 
			// pictureBox1
			// 
			resources->ApplyResources(this->pictureBox1, L"pictureBox1");
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->TabStop = false;
			// 
			// mainPanel
			// 
			resources->ApplyResources(this->mainPanel, L"mainPanel");
			this->mainPanel->Controls->Add(this->FoodLabel);
			this->mainPanel->Controls->Add(this->Pricetag);
			this->mainPanel->Controls->Add(this->Ticket);
			this->mainPanel->Controls->Add(this->Options);
			this->mainPanel->Name = L"mainPanel";
			// 
			// FoodLabel
			// 
			resources->ApplyResources(this->FoodLabel, L"FoodLabel");
			this->FoodLabel->BackColor = System::Drawing::Color::White;
			this->FoodLabel->Controls->Add(this->expLabel);
			this->FoodLabel->Controls->Add(this->manLabel);
			this->FoodLabel->Controls->Add(this->expDate);
			this->FoodLabel->Controls->Add(this->manDate);
			this->FoodLabel->Controls->Add(this->printFoodLabel);
			this->FoodLabel->Controls->Add(this->nameFoodLabelText);
			this->FoodLabel->Controls->Add(this->LogoFoodLabel);
			this->FoodLabel->Name = L"FoodLabel";
			// 
			// expLabel
			// 
			resources->ApplyResources(this->expLabel, L"expLabel");
			this->expLabel->Name = L"expLabel";
			// 
			// manLabel
			// 
			resources->ApplyResources(this->manLabel, L"manLabel");
			this->manLabel->Name = L"manLabel";
			// 
			// expDate
			// 
			resources->ApplyResources(this->expDate, L"expDate");
			this->expDate->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->expDate->Name = L"expDate";
			this->expDate->Value = System::DateTime(2019, 2, 9, 12, 25, 36, 731);
			// 
			// manDate
			// 
			resources->ApplyResources(this->manDate, L"manDate");
			this->manDate->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->manDate->Name = L"manDate";
			// 
			// printFoodLabel
			// 
			resources->ApplyResources(this->printFoodLabel, L"printFoodLabel");
			this->printFoodLabel->BackColor = System::Drawing::Color::Black;
			this->printFoodLabel->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->printFoodLabel->FlatAppearance->BorderSize = 0;
			this->printFoodLabel->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->printFoodLabel->ForeColor = System::Drawing::Color::White;
			this->printFoodLabel->Name = L"printFoodLabel";
			this->printFoodLabel->UseVisualStyleBackColor = false;
			this->printFoodLabel->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::printFoodLabel_MouseClick);
			// 
			// nameFoodLabelText
			// 
			resources->ApplyResources(this->nameFoodLabelText, L"nameFoodLabelText");
			this->nameFoodLabelText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->nameFoodLabelText->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->nameFoodLabelText->Name = L"nameFoodLabelText";
			this->nameFoodLabelText->Enter += gcnew System::EventHandler(this, &MyForm::nameFoodLabelText_Enter);
			this->nameFoodLabelText->Leave += gcnew System::EventHandler(this, &MyForm::nameFoodLabelText_Leave);
			// 
			// LogoFoodLabel
			// 
			resources->ApplyResources(this->LogoFoodLabel, L"LogoFoodLabel");
			this->LogoFoodLabel->Name = L"LogoFoodLabel";
			this->LogoFoodLabel->TabStop = false;
			// 
			// Pricetag
			// 
			resources->ApplyResources(this->Pricetag, L"Pricetag");
			this->Pricetag->BackColor = System::Drawing::Color::White;
			this->Pricetag->Controls->Add(this->FoodNameText);
			this->Pricetag->Controls->Add(this->LogoPriceTag);
			this->Pricetag->Controls->Add(this->Line);
			this->Pricetag->Controls->Add(this->PrintPricetag);
			this->Pricetag->Controls->Add(this->PriceText);
			this->Pricetag->Name = L"Pricetag";
			// 
			// FoodNameText
			// 
			resources->ApplyResources(this->FoodNameText, L"FoodNameText");
			this->FoodNameText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->FoodNameText->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->FoodNameText->Name = L"FoodNameText";
			this->FoodNameText->Enter += gcnew System::EventHandler(this, &MyForm::FoodNameText_Enter);
			this->FoodNameText->Leave += gcnew System::EventHandler(this, &MyForm::FoodNameText_Leave);
			// 
			// LogoPriceTag
			// 
			resources->ApplyResources(this->LogoPriceTag, L"LogoPriceTag");
			this->LogoPriceTag->Name = L"LogoPriceTag";
			this->LogoPriceTag->TabStop = false;
			// 
			// Line
			// 
			resources->ApplyResources(this->Line, L"Line");
			this->Line->Name = L"Line";
			// 
			// PrintPricetag
			// 
			resources->ApplyResources(this->PrintPricetag, L"PrintPricetag");
			this->PrintPricetag->BackColor = System::Drawing::Color::Black;
			this->PrintPricetag->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->PrintPricetag->FlatAppearance->BorderSize = 0;
			this->PrintPricetag->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->PrintPricetag->ForeColor = System::Drawing::Color::White;
			this->PrintPricetag->Name = L"PrintPricetag";
			this->PrintPricetag->UseVisualStyleBackColor = false;
			this->PrintPricetag->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::PrintPricetag_MouseClick);
			// 
			// PriceText
			// 
			resources->ApplyResources(this->PriceText, L"PriceText");
			this->PriceText->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->PriceText->CharacterCasing = System::Windows::Forms::CharacterCasing::Upper;
			this->PriceText->Name = L"PriceText";
			this->PriceText->Enter += gcnew System::EventHandler(this, &MyForm::PriceText_Enter);
			this->PriceText->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::PriceText_KeyPress);
			this->PriceText->Leave += gcnew System::EventHandler(this, &MyForm::PriceText_Leave);
			// 
			// Options
			// 
			resources->ApplyResources(this->Options, L"Options");
			this->Options->BackColor = System::Drawing::Color::White;
			this->Options->Controls->Add(this->saveBtn);
			this->Options->Controls->Add(this->cancelBtn);
			this->Options->Name = L"Options";
			// 
			// saveBtn
			// 
			resources->ApplyResources(this->saveBtn, L"saveBtn");
			this->saveBtn->BackColor = System::Drawing::Color::Black;
			this->saveBtn->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->saveBtn->FlatAppearance->BorderSize = 0;
			this->saveBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->saveBtn->ForeColor = System::Drawing::Color::White;
			this->saveBtn->Name = L"saveBtn";
			this->saveBtn->UseVisualStyleBackColor = false;
			// 
			// cancelBtn
			// 
			resources->ApplyResources(this->cancelBtn, L"cancelBtn");
			this->cancelBtn->BackColor = System::Drawing::Color::Black;
			this->cancelBtn->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->cancelBtn->FlatAppearance->BorderSize = 0;
			this->cancelBtn->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)));
			this->cancelBtn->ForeColor = System::Drawing::Color::White;
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->UseVisualStyleBackColor = false;
			this->cancelBtn->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::cancelBtn_MouseClick);
			// 
			// printDocumentPricetag
			// 
			this->printDocumentPricetag->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MyForm::printDocumentPricetag_PrintPage);
			// 
			// Icons
			// 
			this->Icons->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"Icons.ImageStream")));
			this->Icons->TransparentColor = System::Drawing::Color::Transparent;
			this->Icons->Images->SetKeyName(0, L"MenuImg.png");
			this->Icons->Images->SetKeyName(1, L"minus.png");
			this->Icons->Images->SetKeyName(2, L"Options.png");
			this->Icons->Images->SetKeyName(3, L"plus.png");
			this->Icons->Images->SetKeyName(4, L"PricetagImg.png");
			this->Icons->Images->SetKeyName(5, L"TicketImg.png");
			// 
			// Logos
			// 
			this->Logos->ImageStream = (cli::safe_cast<System::Windows::Forms::ImageListStreamer^>(resources->GetObject(L"Logos.ImageStream")));
			this->Logos->TransparentColor = System::Drawing::Color::Transparent;
			this->Logos->Images->SetKeyName(0, L"Logo2019.png");
			this->Logos->Images->SetKeyName(1, L"LUMOlogo.png");
			// 
			// printDocumentFoodLabel
			// 
			this->printDocumentFoodLabel->PrintPage += gcnew System::Drawing::Printing::PrintPageEventHandler(this, &MyForm::printDocumentFoodLabel_PrintPage);
			// 
			// MyForm
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GrayText;
			this->Controls->Add(this->Menu);
			this->Controls->Add(this->mainPanel);
			this->ForeColor = System::Drawing::Color::Black;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->qr))->EndInit();
			this->Ticket->ResumeLayout(false);
			this->Ticket->PerformLayout();
			this->Menu->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->mainPanel->ResumeLayout(false);
			this->FoodLabel->ResumeLayout(false);
			this->FoodLabel->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoFoodLabel))->EndInit();
			this->Pricetag->ResumeLayout(false);
			this->Pricetag->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LogoPriceTag))->EndInit();
			this->Options->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::String^ styleString(String^ s) {

		switch (s->Length) {
		case 1:
			s = "000" + s;
			break;
		case 2:
			s = "00" + s;
			break;
		case 3:
			s = "0" + s;
			break;
		default:
			break;
		}

		return s;
	}

	private: System::Drawing::Color getUnselectColor() {
		Color c;
		return c = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
			static_cast<System::Int32>(static_cast<System::Byte>(64)));
	}

		private: Boolean typeS = false;
	private: System::Void type_Enter(System::Object^  sender, System::EventArgs^  e) {
		if (!typeS) {
			type->Text = "";
			typeS = true;
		}
	}

	private: System::Void type_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (type->Text == "") {
			type->Text = "VIP";
			typeS = false;
		}
	}

		private: Boolean nameS = false;
	private: System::Void name_Enter(System::Object^  sender, System::EventArgs^  e) {
		if (!nameS) {
			name->Text = "";
			nameS = true;
		}
	}

	private: System::Void name_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (name->Text == "") {
			name->Text = "FOOD NAME";
			nameS = false;
		}
	}
		Boolean plusS = false;
	private: System::Void plus_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		timer->Start();
		plusS = true;
	}

	private: System::Void plus_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		timer->Stop();
		plusS = false;
	}
		Boolean minusS = false;
	private: System::Void minus_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		timer->Start();
		minusS = true;
	}

	private: System::Void minus_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		timer->Stop();
		minusS = false;
	}

	private: System::Void id_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == '0') {
			if (id->Text == "000" && !id->SelectedText->Contains("000")) {
				e->Handled = true;
			}
		}
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
		else if (id->Text->Length == 4) {
			if (e->KeyChar != 0x08) {
				e->Handled = true;
			}
		}
	}
	private: System::Void id_Enter(System::Object^  sender, System::EventArgs^  e) {
		if (id->Text == "0001") {
			id->Text = "";
		}
	}

	private: System::Void id_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (id->Text->Length == 0 || id->Text == "0") {
			id->Text = "0001";
		}
		id->Text = styleString(id->Text);
	}
	private: System::Void idFrom_Enter(System::Object^  sender, System::EventArgs^  e) {
		if (idFrom->Text == "0001") {
			idFrom->Text = "";
		}
	}
	private: System::Void idFrom_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (idFrom->Text->Length == 0 || idFrom->Text == "0") {
			idFrom->Text = "0001";
		}
		idFrom->Text = styleString(idFrom->Text);
	}
	private: System::Void idFrom_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (e->KeyChar == '0') {
			if (idFrom->Text == "000" && !idFrom->SelectedText->Contains("000")) {
				e->Handled = true;
			}
		}
		else if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
		else if (idFrom->Text->Length == 4) {
			if (e->KeyChar != 0x08) {
				e->Handled = true;
			}
		}
	}

	private: System::Void PriceText_KeyPress(System::Object^  sender, System::Windows::Forms::KeyPressEventArgs^  e) {
		if (!Char::IsDigit(e->KeyChar) && e->KeyChar != 0x08) {
			e->Handled = true;
		}
	}
			 Boolean usedPrice = false;
			 String^ tempPriceString;
	private: System::String^ tempPrice() {
		if (!usedPrice) {
			usedPrice = !usedPrice;
			return tempPriceString = PriceText->Text;
		}
		else {
			return tempPriceString;
		}
	}

			 
	private: System::Void PriceText_Enter(System::Object^  sender, System::EventArgs^  e) {
		if (PriceText->Text == tempPrice()) {
			PriceText->Text = "";
		}
		else if(PriceText->Text->Contains(",-")){
			PriceText->Text = PriceText->Text->Remove(PriceText->Text->Length - 2);
		}
	}

	private: System::Void PriceText_Leave(System::Object^  sender, System::EventArgs^  e) {
		double temp;
		if (PriceText->Text != "" ) {
			temp = double::Parse(PriceText->Text);
		}

		if (PriceText->Text == "" || temp <= 0) {
			PriceText->Text = tempPrice();
		}
		else if (temp > 0) {
			PriceText->Text = PriceText->Text + ",-";
		}
	}
			 Boolean used = false;
			 String^ tempName;
	private: System::String^ tempFoodName() {
		if (!used) {
			used = !used;
			return tempName = FoodNameText->Text;
		}
		else {
			return tempName;
		}
	}

			 
	private: System::Void FoodNameText_Enter(System::Object^  sender, System::EventArgs^  e) {
		if (FoodNameText->Text == tempFoodName()) {
			FoodNameText->Text = "";
		}
	}

	private: System::Void FoodNameText_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (FoodNameText->Text == "") {
			FoodNameText->Text = tempFoodName();
		}
	}

	private: System::Void nameFoodLabelText_Enter(System::Object^  sender, System::EventArgs^  e) {
		if (nameFoodLabelText->Text == tempFoodName()) {
			nameFoodLabelText->Text = "";
		}
	}
	
	private: System::Void nameFoodLabelText_Leave(System::Object^  sender, System::EventArgs^  e) {
		if (nameFoodLabelText->Text == "") {
			nameFoodLabelText->Text = tempFoodName();
		}
	}

		 private: int page;
	private: System::Void print_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		/*printDialog->AllowSomePages = true;

		// Show the help button.
		printDialog->ShowHelp = true;*/
		printDialog->Document = printDocumentTicket;
		System::Diagnostics::Debug::WriteLine("hello");
		
		/*printPreviewDialog->Document = printDocument;
		printPreviewDialog->ShowDialog();*/
		
		if (printDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (printDocumentTicket == nullptr)
				System::Windows::Forms::MessageBox::Show("null");

			if (printDialog == nullptr)
				System::Windows::Forms::MessageBox::Show("pnull");
			
			for(page = System::Convert::ToInt32(idFrom->Text); page <= System::Convert::ToInt32(id->Text); page++){
				try
				{
					printDocumentTicket->Print();
				}
				catch (Exception^ ex)
				{
					MessageBox::Show("An error occurred while printing", ex->ToString());
				}
			}
		}
	}
		
	private: System::Void printDocumentTicket_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
		Image^ img = Image::FromFile("QR.png");

		String^ idT;

		idT = System::Convert::ToString(page);
		idT = styleString(idT);

		String^ idString = label->Text + "    " + idT;
		String^ typeString = type->Text;
		String^ nameString = name->Text;
		
		Rectangle displayRectangleid = Rectangle(Point(0, 15), System::Drawing::Size(280, 100));
		Rectangle displayRectangletype = Rectangle(Point(0, 60), System::Drawing::Size(300, 350));
		Rectangle displayRectanglename = Rectangle(Point(0, 187), System::Drawing::Size(300, 350));
		//Alignment of String
		StringFormat^ idS = gcnew StringFormat(StringFormatFlags::NoClip);
		StringFormat^ typeS = gcnew StringFormat(idS);
		StringFormat^ nameS = gcnew StringFormat(idS);
		idS->Alignment = StringAlignment::Far;
		typeS->Alignment = StringAlignment::Center;
		nameS->Alignment = StringAlignment::Center;
		// Font style
		System::Drawing::Font^ idFont = gcnew System::Drawing::Font("Arial", 10, System::Drawing::FontStyle::Regular);
		System::Drawing::Font^ typeFont = gcnew System::Drawing::Font("Arial Narrow", 90, System::Drawing::FontStyle::Regular);
		System::Drawing::Font^ nameFont = gcnew System::Drawing::Font("Arial Narrow", 14, System::Drawing::FontStyle::Bold);
		// Draw the content.
		e->Graphics->DrawImage(img, 6, 6, 80, 80);
		e->Graphics->DrawString(idString, idFont, System::Drawing::Brushes::Black, displayRectangleid, idS);
		e->Graphics->DrawString(typeString, typeFont, System::Drawing::Brushes::Black, displayRectangletype, typeS);
		e->Graphics->DrawString(nameString, nameFont, System::Drawing::Brushes::Black, displayRectanglename, nameS);
		//If more pages
		/*e->HasMorePages = System::Convert::ToInt32(id->Text) - page;
		page++;
		if (e->HasMorePages == 0) {
			page = 1;
		}*/

	}

	private: System::Void PrintPricetag_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		printDialog->Document = printDocumentPricetag;
		System::Diagnostics::Debug::WriteLine("hello");
		if (printDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (printDocumentPricetag == nullptr)
				System::Windows::Forms::MessageBox::Show("null");

			if (printDialog == nullptr)
				System::Windows::Forms::MessageBox::Show("pnull");

			try
			{
				printDocumentPricetag->Print();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("An error occurred while printing", ex->ToString());
			}
		}
	}

	private: System::Void printDocumentPricetag_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
		Image^ img = Image::FromFile("Logo2019.png");
		
		String^ LineString = Line->Text;
		String^ priceString = PriceText->Text;
		String^ nameString = FoodNameText->Text;

		Rectangle displayRectangleline = Rectangle(Point(0, 240), System::Drawing::Size(300, 350));
		Rectangle displayRectangleprice = Rectangle(Point(0, 310), System::Drawing::Size(300, 350));
		Rectangle displayRectanglename = Rectangle(Point(0, 417), System::Drawing::Size(300, 350));

		//Sting Alignment
		StringFormat^ lineS = gcnew StringFormat(StringFormatFlags::NoClip);
		StringFormat^ priceS = gcnew StringFormat(lineS);
		StringFormat^ nameS = gcnew StringFormat(lineS);

		lineS->Alignment = StringAlignment::Center;
		priceS->Alignment = StringAlignment::Center;
		nameS->Alignment = StringAlignment::Center;
		// Font style
		System::Drawing::Font^ lineFont = gcnew System::Drawing::Font("Arial Narrow", 5.5, System::Drawing::FontStyle::Regular);
		System::Drawing::Font^ priceFont = gcnew System::Drawing::Font("Arial Narrow", 65, System::Drawing::FontStyle::Regular);
		System::Drawing::Font^ nameFont = gcnew System::Drawing::Font("Arial Narrow", 14, System::Drawing::FontStyle::Bold);
		// Draw the content.
		e->Graphics->DrawImage(img, 115, 250, 70, 70);
		e->Graphics->DrawString(LineString, lineFont, System::Drawing::Brushes::Black, displayRectangleline, lineS);
		e->Graphics->DrawString(priceString, priceFont, System::Drawing::Brushes::Black, displayRectangleprice, priceS);
		e->Graphics->DrawString(nameString, nameFont, System::Drawing::Brushes::Black, displayRectanglename, nameS);

	}

	private: System::Void printFoodLabel_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		printDialog->Document = printDocumentFoodLabel;
		System::Diagnostics::Debug::WriteLine("hello");
		if (printDialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			if (printDocumentFoodLabel == nullptr)
				System::Windows::Forms::MessageBox::Show("null");

			if (printDialog == nullptr)
				System::Windows::Forms::MessageBox::Show("pnull");

			try
			{
				printDocumentFoodLabel->Print();
			}
			catch (Exception^ ex)
			{
				MessageBox::Show("An error occurred while printing", ex->ToString());
			}
		}
	}

	private: System::Void printDocumentFoodLabel_PrintPage(System::Object^  sender, System::Drawing::Printing::PrintPageEventArgs^  e) {
		Image^ img = Image::FromFile("Logo2019.png");

		String^ nameString = nameFoodLabelText->Text;
		String^ manText = manLabel->Text;
		String^ manDateString = manDate->Text;
		String^ expText = expLabel->Text;
		String^ expDateString = expDate->Text;

		Rectangle displayRectanglename = Rectangle(Point(0, 90), System::Drawing::Size(300, 350));
		Rectangle displayRectanglemanText = Rectangle(Point(0, 140), System::Drawing::Size(129, 350));
		Rectangle displayRectanglemanDate = Rectangle(Point(130, 140), System::Drawing::Size(191, 350));
		Rectangle displayRectangleexpText = Rectangle(Point(0, 170), System::Drawing::Size(129, 350));
		Rectangle displayRectangleexpDate = Rectangle(Point(130, 170), System::Drawing::Size(191, 350));
		//Sting Alignment
		StringFormat^ nameS = gcnew StringFormat(StringFormatFlags::NoClip);
		StringFormat^ mantS = gcnew StringFormat(StringFormatFlags::NoClip);
		StringFormat^ manDateS = gcnew StringFormat(StringFormatFlags::NoClip);
		StringFormat^ exptS = gcnew StringFormat(StringFormatFlags::NoClip);
		StringFormat^ expDateS = gcnew StringFormat(StringFormatFlags::NoClip);
		
		nameS->Alignment = StringAlignment::Center;
		mantS->Alignment = StringAlignment::Far;
		manDateS->Alignment = StringAlignment::Near;
		exptS->Alignment = StringAlignment::Far;
		expDateS->Alignment = StringAlignment::Near;

		// Font style
		System::Drawing::Font^ nameFont = gcnew System::Drawing::Font("Arial Narrow", 14, System::Drawing::FontStyle::Bold);
		System::Drawing::Font^ dateFont = gcnew System::Drawing::Font("Arial Narrow", 11, System::Drawing::FontStyle::Bold);
		// Draw the content.
		e->Graphics->DrawImage(img, 115, 5, 70, 70);
		e->Graphics->DrawString(nameString, nameFont, System::Drawing::Brushes::Black, displayRectanglename, nameS);
		e->Graphics->DrawString(manText, dateFont, System::Drawing::Brushes::Black, displayRectanglemanText, mantS);
		e->Graphics->DrawString(manDateString, dateFont, System::Drawing::Brushes::Black, displayRectanglemanDate, manDateS);
		e->Graphics->DrawString(expText, dateFont, System::Drawing::Brushes::Black, displayRectangleexpText, exptS);
		e->Graphics->DrawString(expDateString, dateFont, System::Drawing::Brushes::Black, displayRectangleexpDate, expDateS);
	}

	private: System::Void cancelBtn_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->optionsBtn->BackColor = getUnselectColor();
		this->Options->Visible = false;
	}

	private: System::Void timer_Tick(System::Object^  sender, System::EventArgs^  e) {
		if (plusS) {
			int i = System::Convert::ToInt32(id->Text);
			if (i < 9999) {
				i++;
			}
			id->Text = System::Convert::ToString(i);
			id->Text = styleString(id->Text);
		}
		else if (minusS) {
			int i = System::Convert::ToInt32(id->Text);
			if (i>1) {
				i--;
			}
			id->Text = System::Convert::ToString(i);
			id->Text = styleString(id->Text);
		}
	}

	/* Menu START*/

	private: System::Void ticketBtn_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->ticketBtn->BackColor = System::Drawing::Color::RoyalBlue;
		this->pricetagBtn->BackColor = getUnselectColor();
		this->optionsBtn->BackColor = getUnselectColor();
		this->foodLabelBtn->BackColor = getUnselectColor();
		this->Ticket->Visible = true;
		this->Pricetag->Visible = false;
		this->FoodLabel->Visible = false;
		this->Options->Visible = false;
	}

	private: System::Void pricetagBtn_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->pricetagBtn->BackColor = System::Drawing::Color::RoyalBlue;
		this->ticketBtn->BackColor = getUnselectColor();
		this->optionsBtn->BackColor = getUnselectColor();
		this->foodLabelBtn->BackColor = getUnselectColor();
		this->Pricetag->Visible = true;
		this->Ticket->Visible = false;
		this->FoodLabel->Visible = false;
		this->Options->Visible = false;
	}
	
	private: System::Void foodLabelBtn_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->foodLabelBtn->BackColor = System::Drawing::Color::RoyalBlue;

		this->ticketBtn->BackColor = getUnselectColor();
		this->pricetagBtn->BackColor = getUnselectColor();
		this->optionsBtn->BackColor = getUnselectColor();

		this->FoodLabel->Visible = true;
		this->Ticket->Visible = false;
		this->Pricetag->Visible = false;
		this->Options->Visible = false;
	}	
	
	private: System::Void OptionsBtn_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		this->optionsBtn->BackColor = System::Drawing::Color::RoyalBlue;
		this->ticketBtn->BackColor = getUnselectColor();
		this->pricetagBtn->BackColor = getUnselectColor();
		this->foodLabelBtn->BackColor = getUnselectColor();

		this->Options->Visible = true;
		this->Ticket->Visible = false;
		this->Pricetag->Visible = false;
		this->FoodLabel->Visible = false;
	}

			 /* Menu width*/
			 bool menuText = true;
	private: System::Void menuBtn_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e) {
		if (!menuText) { // with text
			this->Menu->Size = System::Drawing::Size( this->ticketBtn->Size.Width , 422);
			this->mainPanel->Location = System::Drawing::Point((this->mainPanel->Location.X + (this->ticketBtn->Size.Width - this->menuBtn->Size.Width)), 0);
			//this->mainPanel->Size = System::Drawing::Size((this->mainPanel->Size.Width - (this->ticketBtn->Size.Width - this->menuBtn->Size.Width)), this->mainPanel->Size.Height-46);
			menuText = true;
		}
		else { //without text
			this->Menu->Size = System::Drawing::Size(this->menuBtn->Size.Width, 422);
			this->mainPanel->Location = System::Drawing::Point((this->mainPanel->Location.X - (this->ticketBtn->Size.Width - this->menuBtn->Size.Width)), 0);
			//this->mainPanel->Size = System::Drawing::Size((this->mainPanel->Size.Width + (this->ticketBtn->Size.Width - this->menuBtn->Size.Width)), this->mainPanel->Size.Height+46);
			menuText = false;
		}
	}
	
	/* Menu END*/
};
}
