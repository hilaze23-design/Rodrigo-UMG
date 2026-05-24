#pragma once
#include "factura.h"
#include "producto.h"
#include "empleado.h"
#include "cliente.h"

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class contenido : public System::Windows::Forms::Form
	{
	public:
		contenido(void) { InitializeComponent(); }
	protected:
		~contenido() { if (components) delete components; }

	private:
		// Sidebar
		System::Windows::Forms::Panel^ panel_lateral;
		System::Windows::Forms::Panel^ panel_logo_area;
		System::Windows::Forms::Label^ lbl_logo;
		System::Windows::Forms::Label^ lbl_sub_logo;
		System::Windows::Forms::Button^ btn_factura;
		System::Windows::Forms::Button^ btn_producto;
		System::Windows::Forms::Button^ btn_empleado;
		System::Windows::Forms::Button^ btn_clientes;

		// Panel principal
		System::Windows::Forms::Panel^ panel_contenedor;
		System::Windows::Forms::Panel^ panel_header;
		System::Windows::Forms::Label^ lbl_bienvenido;
		System::Windows::Forms::Label^ lbl_sub_bienvenido;
		System::Windows::Forms::Panel^ panel_badge;
		System::Windows::Forms::Label^ lbl_dot;
		System::Windows::Forms::Label^ lbl_cajero;

		// Boton volver al inicio
		System::Windows::Forms::Button^ btn_volver;

		// Tarjetas
		System::Windows::Forms::Panel^ panel_card1;
		System::Windows::Forms::Label^ lbl_icon1;
		System::Windows::Forms::Label^ lbl_card1_titulo;
		System::Windows::Forms::Label^ lbl_card1_valor;

		System::Windows::Forms::Panel^ panel_card2;
		System::Windows::Forms::Label^ lbl_icon2;
		System::Windows::Forms::Label^ lbl_card2_titulo;
		System::Windows::Forms::Label^ lbl_card2_valor;

		System::Windows::Forms::Panel^ panel_card3;
		System::Windows::Forms::Label^ lbl_icon3;
		System::Windows::Forms::Label^ lbl_card3_titulo;
		System::Windows::Forms::Label^ lbl_card3_valor;

		// Footer
		System::Windows::Forms::Label^ lbl_conexion;

		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->panel_lateral = (gcnew System::Windows::Forms::Panel());
			this->btn_clientes = (gcnew System::Windows::Forms::Button());
			this->btn_empleado = (gcnew System::Windows::Forms::Button());
			this->btn_producto = (gcnew System::Windows::Forms::Button());
			this->btn_factura = (gcnew System::Windows::Forms::Button());
			this->panel_logo_area = (gcnew System::Windows::Forms::Panel());
			this->lbl_logo = (gcnew System::Windows::Forms::Label());
			this->lbl_sub_logo = (gcnew System::Windows::Forms::Label());
			this->panel_contenedor = (gcnew System::Windows::Forms::Panel());
			this->lbl_conexion = (gcnew System::Windows::Forms::Label());
			this->panel_card3 = (gcnew System::Windows::Forms::Panel());
			this->lbl_card3_valor = (gcnew System::Windows::Forms::Label());
			this->lbl_card3_titulo = (gcnew System::Windows::Forms::Label());
			this->lbl_icon3 = (gcnew System::Windows::Forms::Label());
			this->panel_card2 = (gcnew System::Windows::Forms::Panel());
			this->lbl_card2_valor = (gcnew System::Windows::Forms::Label());
			this->lbl_card2_titulo = (gcnew System::Windows::Forms::Label());
			this->lbl_icon2 = (gcnew System::Windows::Forms::Label());
			this->panel_card1 = (gcnew System::Windows::Forms::Panel());
			this->lbl_card1_valor = (gcnew System::Windows::Forms::Label());
			this->lbl_card1_titulo = (gcnew System::Windows::Forms::Label());
			this->lbl_icon1 = (gcnew System::Windows::Forms::Label());
			this->panel_header = (gcnew System::Windows::Forms::Panel());
			this->panel_badge = (gcnew System::Windows::Forms::Panel());
			this->lbl_cajero = (gcnew System::Windows::Forms::Label());
			this->lbl_dot = (gcnew System::Windows::Forms::Label());
			this->lbl_sub_bienvenido = (gcnew System::Windows::Forms::Label());
			this->lbl_bienvenido = (gcnew System::Windows::Forms::Label());
			this->btn_volver = (gcnew System::Windows::Forms::Button());
			this->panel_lateral->SuspendLayout();
			this->panel_logo_area->SuspendLayout();
			this->panel_contenedor->SuspendLayout();
			this->panel_card3->SuspendLayout();
			this->panel_card2->SuspendLayout();
			this->panel_card1->SuspendLayout();
			this->panel_header->SuspendLayout();
			this->panel_badge->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel_lateral
			// 
			this->panel_lateral->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->panel_lateral->Controls->Add(this->btn_clientes);
			this->panel_lateral->Controls->Add(this->btn_empleado);
			this->panel_lateral->Controls->Add(this->btn_producto);
			this->panel_lateral->Controls->Add(this->btn_factura);
			this->panel_lateral->Controls->Add(this->panel_logo_area);
			this->panel_lateral->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel_lateral->Location = System::Drawing::Point(0, 0);
			this->panel_lateral->Name = L"panel_lateral";
			this->panel_lateral->Size = System::Drawing::Size(250, 550);
			this->panel_lateral->TabIndex = 0;
			// 
			// btn_clientes
			// 
			this->btn_clientes->BackColor = System::Drawing::Color::Transparent;
			this->btn_clientes->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_clientes->FlatAppearance->BorderSize = 0;
			this->btn_clientes->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->btn_clientes->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_clientes->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9));
			this->btn_clientes->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btn_clientes->Location = System::Drawing::Point(12, 277);
			this->btn_clientes->Name = L"btn_clientes";
			this->btn_clientes->Size = System::Drawing::Size(226, 45);
			this->btn_clientes->TabIndex = 4;
			this->btn_clientes->Text = L"   Clientes";
			this->btn_clientes->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_clientes->UseVisualStyleBackColor = false;
			this->btn_clientes->Click += gcnew System::EventHandler(this, &contenido::btn_clientes_Click);
			// 
			// btn_empleado
			// 
			this->btn_empleado->BackColor = System::Drawing::Color::Transparent;
			this->btn_empleado->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_empleado->FlatAppearance->BorderSize = 0;
			this->btn_empleado->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->btn_empleado->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_empleado->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9));
			this->btn_empleado->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btn_empleado->Location = System::Drawing::Point(12, 222);
			this->btn_empleado->Name = L"btn_empleado";
			this->btn_empleado->Size = System::Drawing::Size(226, 45);
			this->btn_empleado->TabIndex = 3;
			this->btn_empleado->Text = L"   Empleados";
			this->btn_empleado->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_empleado->UseVisualStyleBackColor = false;
			this->btn_empleado->Click += gcnew System::EventHandler(this, &contenido::btn_empleado_Click);
			// 
			// btn_producto
			// 
			this->btn_producto->BackColor = System::Drawing::Color::Transparent;
			this->btn_producto->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_producto->FlatAppearance->BorderSize = 0;
			this->btn_producto->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(60)));
			this->btn_producto->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_producto->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9));
			this->btn_producto->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btn_producto->Location = System::Drawing::Point(12, 167);
			this->btn_producto->Name = L"btn_producto";
			this->btn_producto->Size = System::Drawing::Size(226, 45);
			this->btn_producto->TabIndex = 2;
			this->btn_producto->Text = L"   Inventario";
			this->btn_producto->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_producto->UseVisualStyleBackColor = false;
			this->btn_producto->Click += gcnew System::EventHandler(this, &contenido::btn_producto_Click);
			// 
			// btn_factura
			// 
			this->btn_factura->BackColor = System::Drawing::Color::Transparent;
			this->btn_factura->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_factura->FlatAppearance->BorderSize = 0;
			this->btn_factura->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_factura->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular));
			this->btn_factura->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(190)), static_cast<System::Int32>(static_cast<System::Byte>(190)),
				static_cast<System::Int32>(static_cast<System::Byte>(215)));
			this->btn_factura->Location = System::Drawing::Point(12, 112);
			this->btn_factura->Name = L"btn_factura";
			this->btn_factura->Size = System::Drawing::Size(226, 45);
			this->btn_factura->TabIndex = 1;
			this->btn_factura->Text = L"   Facturación";
			this->btn_factura->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->btn_factura->UseVisualStyleBackColor = false;
			this->btn_factura->Click += gcnew System::EventHandler(this, &contenido::btn_factura_Click);
			// 
			// panel_logo_area
			// 
			this->panel_logo_area->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(35)));
			this->panel_logo_area->Controls->Add(this->lbl_logo);
			this->panel_logo_area->Controls->Add(this->lbl_sub_logo);
			this->panel_logo_area->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_logo_area->Location = System::Drawing::Point(0, 0);
			this->panel_logo_area->Name = L"panel_logo_area";
			this->panel_logo_area->Size = System::Drawing::Size(250, 100);
			this->panel_logo_area->TabIndex = 0;
			// 
			// lbl_logo
			// 
			this->lbl_logo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15, System::Drawing::FontStyle::Bold));
			this->lbl_logo->ForeColor = System::Drawing::Color::White;
			this->lbl_logo->Location = System::Drawing::Point(15, 22);
			this->lbl_logo->Name = L"lbl_logo";
			this->lbl_logo->Size = System::Drawing::Size(220, 35);
			this->lbl_logo->TabIndex = 0;
			this->lbl_logo->Text = L"UMG-MARKET";
			// 
			// lbl_sub_logo
			// 
			this->lbl_sub_logo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7));
			this->lbl_sub_logo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->lbl_sub_logo->Location = System::Drawing::Point(18, 60);
			this->lbl_sub_logo->Name = L"lbl_sub_logo";
			this->lbl_sub_logo->Size = System::Drawing::Size(200, 18);
			this->lbl_sub_logo->TabIndex = 1;
			this->lbl_sub_logo->Text = L"SUPERMERCADO";
			// 
			// panel_contenedor
			// 
			this->panel_contenedor->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->panel_contenedor->Controls->Add(this->lbl_conexion);
			this->panel_contenedor->Controls->Add(this->panel_card3);
			this->panel_contenedor->Controls->Add(this->panel_card2);
			this->panel_contenedor->Controls->Add(this->panel_card1);
			this->panel_contenedor->Controls->Add(this->panel_header);
			this->panel_contenedor->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel_contenedor->Location = System::Drawing::Point(250, 0);
			this->panel_contenedor->Name = L"panel_contenedor";
			this->panel_contenedor->Size = System::Drawing::Size(734, 550);
			this->panel_contenedor->TabIndex = 1;
			this->panel_contenedor->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &contenido::panel_contenedor_Paint);
			// 
			// lbl_conexion
			// 
			this->lbl_conexion->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7));
			this->lbl_conexion->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(90)), static_cast<System::Int32>(static_cast<System::Byte>(90)),
				static_cast<System::Int32>(static_cast<System::Byte>(120)));
			this->lbl_conexion->Location = System::Drawing::Point(390, 515);
			this->lbl_conexion->Name = L"lbl_conexion";
			this->lbl_conexion->Size = System::Drawing::Size(330, 20);
			this->lbl_conexion->TabIndex = 0;
			this->lbl_conexion->Text = L"Conexión activa a MySQL servidor local";
			this->lbl_conexion->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// panel_card3
			// 
			this->panel_card3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->panel_card3->Controls->Add(this->lbl_card3_valor);
			this->panel_card3->Controls->Add(this->lbl_card3_titulo);
			this->panel_card3->Controls->Add(this->lbl_icon3);
			this->panel_card3->Location = System::Drawing::Point(485, 100);
			this->panel_card3->Name = L"panel_card3";
			this->panel_card3->Size = System::Drawing::Size(210, 115);
			this->panel_card3->TabIndex = 3;
			// 
			// lbl_card3_valor
			// 
			this->lbl_card3_valor->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15, System::Drawing::FontStyle::Bold));
			this->lbl_card3_valor->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lbl_card3_valor->Location = System::Drawing::Point(15, 72);
			this->lbl_card3_valor->Name = L"lbl_card3_valor";
			this->lbl_card3_valor->Size = System::Drawing::Size(185, 32);
			this->lbl_card3_valor->TabIndex = 0;
			this->lbl_card3_valor->Text = L"0 ítems";
			// 
			// lbl_card3_titulo
			// 
			this->lbl_card3_titulo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7, System::Drawing::FontStyle::Bold));
			this->lbl_card3_titulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->lbl_card3_titulo->Location = System::Drawing::Point(15, 52);
			this->lbl_card3_titulo->Name = L"lbl_card3_titulo";
			this->lbl_card3_titulo->Size = System::Drawing::Size(185, 18);
			this->lbl_card3_titulo->TabIndex = 1;
			this->lbl_card3_titulo->Text = L"ALERTAS STOCK";
			// 
			// lbl_icon3
			// 
			this->lbl_icon3->AutoSize = true;
			this->lbl_icon3->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16));
			this->lbl_icon3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->lbl_icon3->Location = System::Drawing::Point(15, 12);
			this->lbl_icon3->Name = L"lbl_icon3";
			this->lbl_icon3->Size = System::Drawing::Size(32, 30);
			this->lbl_icon3->TabIndex = 2;
			this->lbl_icon3->Text = L"▲";
			// 
			// panel_card2
			// 
			this->panel_card2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->panel_card2->Controls->Add(this->lbl_card2_valor);
			this->panel_card2->Controls->Add(this->lbl_card2_titulo);
			this->panel_card2->Controls->Add(this->lbl_icon2);
			this->panel_card2->Location = System::Drawing::Point(255, 100);
			this->panel_card2->Name = L"panel_card2";
			this->panel_card2->Size = System::Drawing::Size(210, 115);
			this->panel_card2->TabIndex = 2;
			// 
			// lbl_card2_valor
			// 
			this->lbl_card2_valor->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15, System::Drawing::FontStyle::Bold));
			this->lbl_card2_valor->ForeColor = System::Drawing::Color::White;
			this->lbl_card2_valor->Location = System::Drawing::Point(15, 72);
			this->lbl_card2_valor->Name = L"lbl_card2_valor";
			this->lbl_card2_valor->Size = System::Drawing::Size(185, 32);
			this->lbl_card2_valor->TabIndex = 0;
			this->lbl_card2_valor->Text = L"Q 0.00";
			// 
			// lbl_card2_titulo
			// 
			this->lbl_card2_titulo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7, System::Drawing::FontStyle::Bold));
			this->lbl_card2_titulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->lbl_card2_titulo->Location = System::Drawing::Point(15, 52);
			this->lbl_card2_titulo->Name = L"lbl_card2_titulo";
			this->lbl_card2_titulo->Size = System::Drawing::Size(185, 18);
			this->lbl_card2_titulo->TabIndex = 1;
			this->lbl_card2_titulo->Text = L"VENTAS DEL TURNO";
			// 
			// lbl_icon2
			// 
			this->lbl_icon2->AutoSize = true;
			this->lbl_icon2->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16));
			this->lbl_icon2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbl_icon2->Location = System::Drawing::Point(15, 12);
			this->lbl_icon2->Name = L"lbl_icon2";
			this->lbl_icon2->Size = System::Drawing::Size(32, 30);
			this->lbl_icon2->TabIndex = 2;
			this->lbl_icon2->Text = L"▤";
			// 
			// panel_card1
			// 
			this->panel_card1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(35)), static_cast<System::Int32>(static_cast<System::Byte>(35)),
				static_cast<System::Int32>(static_cast<System::Byte>(52)));
			this->panel_card1->Controls->Add(this->lbl_card1_valor);
			this->panel_card1->Controls->Add(this->lbl_card1_titulo);
			this->panel_card1->Controls->Add(this->lbl_icon1);
			this->panel_card1->Location = System::Drawing::Point(25, 100);
			this->panel_card1->Name = L"panel_card1";
			this->panel_card1->Size = System::Drawing::Size(210, 115);
			this->panel_card1->TabIndex = 1;
			// 
			// lbl_card1_valor
			// 
			this->lbl_card1_valor->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 15, System::Drawing::FontStyle::Bold));
			this->lbl_card1_valor->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lbl_card1_valor->Location = System::Drawing::Point(15, 72);
			this->lbl_card1_valor->Name = L"lbl_card1_valor";
			this->lbl_card1_valor->Size = System::Drawing::Size(185, 32);
			this->lbl_card1_valor->TabIndex = 0;
			this->lbl_card1_valor->Text = L"Abierta";
			// 
			// lbl_card1_titulo
			// 
			this->lbl_card1_titulo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 7, System::Drawing::FontStyle::Bold));
			this->lbl_card1_titulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->lbl_card1_titulo->Location = System::Drawing::Point(15, 52);
			this->lbl_card1_titulo->Name = L"lbl_card1_titulo";
			this->lbl_card1_titulo->Size = System::Drawing::Size(185, 18);
			this->lbl_card1_titulo->TabIndex = 1;
			this->lbl_card1_titulo->Text = L"ESTADO DE CAJA";
			// 
			// lbl_icon1
			// 
			this->lbl_icon1->AutoSize = true;
			this->lbl_icon1->Font = (gcnew System::Drawing::Font(L"Segoe UI Symbol", 16));
			this->lbl_icon1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->lbl_icon1->Location = System::Drawing::Point(15, 12);
			this->lbl_icon1->Name = L"lbl_icon1";
			this->lbl_icon1->Size = System::Drawing::Size(32, 30);
			this->lbl_icon1->TabIndex = 2;
			this->lbl_icon1->Text = L"▣";
			// 
			// panel_header
			// 
			this->panel_header->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->panel_header->Controls->Add(this->btn_volver);
			this->panel_header->Controls->Add(this->panel_badge);
			this->panel_header->Controls->Add(this->lbl_sub_bienvenido);
			this->panel_header->Controls->Add(this->lbl_bienvenido);
			this->panel_header->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel_header->Location = System::Drawing::Point(0, 0);
			this->panel_header->Name = L"panel_header";
			this->panel_header->Size = System::Drawing::Size(734, 80);
			this->panel_header->TabIndex = 0;
			// 
			// btn_volver
			// 
			this->btn_volver->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->btn_volver->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btn_volver->FlatAppearance->BorderSize = 0;
			this->btn_volver->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(122)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btn_volver->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_volver->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Bold));
			this->btn_volver->ForeColor = System::Drawing::Color::White;
			this->btn_volver->Location = System::Drawing::Point(25, 24);
			this->btn_volver->Name = L"btn_volver";
			this->btn_volver->Size = System::Drawing::Size(110, 32);
			this->btn_volver->TabIndex = 5;
			this->btn_volver->Text = L"← Inicio";
			this->btn_volver->UseVisualStyleBackColor = false;
			this->btn_volver->Visible = false;
			this->btn_volver->Click += gcnew System::EventHandler(this, &contenido::btn_volver_Click);
			// 
			// panel_badge
			// 
			this->panel_badge->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(30)));
			this->panel_badge->Controls->Add(this->lbl_cajero);
			this->panel_badge->Controls->Add(this->lbl_dot);
			this->panel_badge->Location = System::Drawing::Point(555, 25);
			this->panel_badge->Name = L"panel_badge";
			this->panel_badge->Size = System::Drawing::Size(145, 30);
			this->panel_badge->TabIndex = 0;
			// 
			// lbl_cajero
			// 
			this->lbl_cajero->AutoSize = true;
			this->lbl_cajero->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8, System::Drawing::FontStyle::Bold));
			this->lbl_cajero->ForeColor = System::Drawing::Color::White;
			this->lbl_cajero->Location = System::Drawing::Point(28, 9);
			this->lbl_cajero->Name = L"lbl_cajero";
			this->lbl_cajero->Size = System::Drawing::Size(79, 16);
			this->lbl_cajero->TabIndex = 0;
			this->lbl_cajero->Text = L"Cajero Activo";
			// 
			// lbl_dot
			// 
			this->lbl_dot->AutoSize = true;
			this->lbl_dot->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10, System::Drawing::FontStyle::Bold));
			this->lbl_dot->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(210)),
				static_cast<System::Int32>(static_cast<System::Byte>(100)));
			this->lbl_dot->Location = System::Drawing::Point(8, 6);
			this->lbl_dot->Name = L"lbl_dot";
			this->lbl_dot->Size = System::Drawing::Size(18, 19);
			this->lbl_dot->TabIndex = 1;
			this->lbl_dot->Text = L"●";
			// 
			// lbl_sub_bienvenido
			// 
			this->lbl_sub_bienvenido->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 8));
			this->lbl_sub_bienvenido->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(130)),
				static_cast<System::Int32>(static_cast<System::Byte>(130)), static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->lbl_sub_bienvenido->Location = System::Drawing::Point(27, 48);
			this->lbl_sub_bienvenido->Name = L"lbl_sub_bienvenido";
			this->lbl_sub_bienvenido->Size = System::Drawing::Size(430, 20);
			this->lbl_sub_bienvenido->TabIndex = 1;
			this->lbl_sub_bienvenido->Text = L"Selecciona una opción del menú para comenzar a operar.";
			// 
			// lbl_bienvenido
			// 
			this->lbl_bienvenido->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 16, System::Drawing::FontStyle::Bold));
			this->lbl_bienvenido->ForeColor = System::Drawing::Color::White;
			this->lbl_bienvenido->Location = System::Drawing::Point(25, 10);
			this->lbl_bienvenido->Name = L"lbl_bienvenido";
			this->lbl_bienvenido->Size = System::Drawing::Size(500, 35);
			this->lbl_bienvenido->TabIndex = 2;
			this->lbl_bienvenido->Text = L"¡Bienvenido al Sistema!";
			// 
			// contenido
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->ClientSize = System::Drawing::Size(984, 550);
			this->Controls->Add(this->panel_contenedor);
			this->Controls->Add(this->panel_lateral);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"contenido";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"UMG-MARKET";
			this->panel_lateral->ResumeLayout(false);
			this->panel_logo_area->ResumeLayout(false);
			this->panel_contenedor->ResumeLayout(false);
			this->panel_card3->ResumeLayout(false);
			this->panel_card3->PerformLayout();
			this->panel_card2->ResumeLayout(false);
			this->panel_card2->PerformLayout();
			this->panel_card1->ResumeLayout(false);
			this->panel_card1->PerformLayout();
			this->panel_header->ResumeLayout(false);
			this->panel_badge->ResumeLayout(false);
			this->panel_badge->PerformLayout();
			this->ResumeLayout(false);
		}
#pragma endregion

		// ==================== HELPERS ====================

		void ResetBotones()
		{
			array<Button^>^ btns = { btn_factura, btn_producto, btn_empleado, btn_clientes };
			for each (Button ^ b in btns)
			{
				b->BackColor = System::Drawing::Color::Transparent;
				b->ForeColor = System::Drawing::Color::FromArgb(190, 190, 215);
				b->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular));
			}
		}

		void SetBotonActivo(Button^ btn)
		{
			ResetBotones();
			btn->BackColor = System::Drawing::Color::FromArgb(0, 122, 255);
			btn->ForeColor = System::Drawing::Color::White;
			btn->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Bold));
		}

		void MostrarInicio()
		{
			// Eliminar cualquier formulario hijo abierto
			for (int i = panel_contenedor->Controls->Count - 1; i >= 0; i--)
			{
				if (dynamic_cast<Form^>(panel_contenedor->Controls[i]) != nullptr)
					panel_contenedor->Controls->RemoveAt(i);
			}
			// Restaurar tarjetas y textos del header
			panel_card1->Visible = true;
			panel_card2->Visible = true;
			panel_card3->Visible = true;
			lbl_bienvenido->Visible = true;
			lbl_sub_bienvenido->Visible = true;
			// Ocultar boton volver y resetear sidebar
			btn_volver->Visible = false;
			ResetBotones();
		}

		void CargarFormulario(Form^ formulario)
		{
			// Ocultar tarjetas y textos del dashboard
			panel_card1->Visible = false;
			panel_card2->Visible = false;
			panel_card3->Visible = false;
			lbl_bienvenido->Visible = false;
			lbl_sub_bienvenido->Visible = false;

			// Eliminar formulario anterior si habia uno
			for (int i = panel_contenedor->Controls->Count - 1; i >= 0; i--)
			{
				if (dynamic_cast<Form^>(panel_contenedor->Controls[i]) != nullptr)
					panel_contenedor->Controls->RemoveAt(i);
			}

			// Insertar el nuevo formulario
			formulario->TopLevel = false;
			formulario->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			formulario->Dock = System::Windows::Forms::DockStyle::Fill;
			panel_contenedor->Controls->Add(formulario);
			formulario->BringToFront();
			formulario->Show();

			// Mostrar boton volver
			btn_volver->Visible = true;
			btn_volver->BringToFront();
		}

		// ==================== EVENTOS ====================

	private: System::Void btn_factura_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SetBotonActivo(btn_factura);
		CargarFormulario(gcnew CppCLRWinFormsProject::factura());
	}
	private: System::Void btn_producto_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SetBotonActivo(btn_producto);
		CargarFormulario(gcnew CppCLRWinFormsProject::producto());
	}
	private: System::Void btn_empleado_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SetBotonActivo(btn_empleado);
		CargarFormulario(gcnew CppCLRWinFormsProject::empleado());
	}
	private: System::Void btn_clientes_Click(System::Object^ sender, System::EventArgs^ e)
	{
		SetBotonActivo(btn_clientes);
		CargarFormulario(gcnew CppCLRWinFormsProject::cliente());
	}
	private: System::Void btn_volver_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MostrarInicio();
	}
	private: System::Void panel_contenedor_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}
	};
}