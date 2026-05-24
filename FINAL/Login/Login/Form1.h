#pragma once
#pragma execution_character_set("utf-8")
#include "contenido.h"

namespace CppCLRWinFormsProject {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace MySql::Data::MySqlClient;

    public ref class Form1 : public System::Windows::Forms::Form
    {
    public:
        Form1(void) { InitializeComponent(); }
    protected:
        ~Form1() { if (components) delete components; }

    private:
        // Cadena de conexion a la base de datos
        String^ connectionString = "server=localhost;database=facturas;uid=root;pwd=12345;";

        System::Windows::Forms::Label^ lbl_icono;
        System::Windows::Forms::Label^ lbl_titulo;
        System::Windows::Forms::Label^ lbl_subtitulo;
        System::Windows::Forms::Label^ lbl_usuario;
        System::Windows::Forms::Panel^ panel_usuario;
        System::Windows::Forms::Label^ lbl_icon_user;
        System::Windows::Forms::TextBox^ txt_usuario;
        System::Windows::Forms::Label^ lbl_contra;
        System::Windows::Forms::Panel^ panel_contra;
        System::Windows::Forms::Label^ lbl_icon_lock;
        System::Windows::Forms::TextBox^ txt_contra;
        System::Windows::Forms::Button^ btn_acceso;
        System::Windows::Forms::Label^ lbl_error;

        System::ComponentModel::Container^ components;
        CppCLRWinFormsProject::contenido^ contenidoForm;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lbl_icono = (gcnew System::Windows::Forms::Label());
            this->lbl_titulo = (gcnew System::Windows::Forms::Label());
            this->lbl_subtitulo = (gcnew System::Windows::Forms::Label());
            this->lbl_usuario = (gcnew System::Windows::Forms::Label());
            this->panel_usuario = (gcnew System::Windows::Forms::Panel());
            this->lbl_icon_user = (gcnew System::Windows::Forms::Label());
            this->txt_usuario = (gcnew System::Windows::Forms::TextBox());
            this->lbl_contra = (gcnew System::Windows::Forms::Label());
            this->panel_contra = (gcnew System::Windows::Forms::Panel());
            this->lbl_icon_lock = (gcnew System::Windows::Forms::Label());
            this->txt_contra = (gcnew System::Windows::Forms::TextBox());
            this->btn_acceso = (gcnew System::Windows::Forms::Button());
            this->lbl_error = (gcnew System::Windows::Forms::Label());
            this->panel_usuario->SuspendLayout();
            this->panel_contra->SuspendLayout();
            this->SuspendLayout();
            // 
            // lbl_icono
            // 
            this->lbl_icono->Font = (gcnew System::Drawing::Font(L"Segoe UI", 28, System::Drawing::FontStyle::Bold));
            this->lbl_icono->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->lbl_icono->Location = System::Drawing::Point(0, 30);
            this->lbl_icono->Name = L"lbl_icono";
            this->lbl_icono->Size = System::Drawing::Size(340, 55);
            this->lbl_icono->TabIndex = 7;
            this->lbl_icono->Text = L"[ UMG ]";
            this->lbl_icono->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lbl_titulo
            // 
            this->lbl_titulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
            this->lbl_titulo->ForeColor = System::Drawing::Color::White;
            this->lbl_titulo->Location = System::Drawing::Point(0, 88);
            this->lbl_titulo->Name = L"lbl_titulo";
            this->lbl_titulo->Size = System::Drawing::Size(340, 40);
            this->lbl_titulo->TabIndex = 6;
            this->lbl_titulo->Text = L"UMG-MARKET";
            this->lbl_titulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lbl_titulo->Click += gcnew System::EventHandler(this, &Form1::lbl_titulo_Click);
            // 
            // lbl_subtitulo
            // 
            this->lbl_subtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lbl_subtitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
                static_cast<System::Int32>(static_cast<System::Byte>(155)));
            this->lbl_subtitulo->Location = System::Drawing::Point(0, 130);
            this->lbl_subtitulo->Name = L"lbl_subtitulo";
            this->lbl_subtitulo->Size = System::Drawing::Size(340, 22);
            this->lbl_subtitulo->TabIndex = 5;
            this->lbl_subtitulo->Text = L"CONTROL DE ACCESO";
            this->lbl_subtitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lbl_usuario
            // 
            this->lbl_usuario->AutoSize = true;
            this->lbl_usuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_usuario->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
                static_cast<System::Int32>(static_cast<System::Byte>(155)));
            this->lbl_usuario->Location = System::Drawing::Point(35, 170);
            this->lbl_usuario->Name = L"lbl_usuario";
            this->lbl_usuario->Size = System::Drawing::Size(55, 13);
            this->lbl_usuario->TabIndex = 4;
            this->lbl_usuario->Text = L"USUARIO";
            // 
            // panel_usuario
            // 
            this->panel_usuario->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->panel_usuario->Controls->Add(this->lbl_icon_user);
            this->panel_usuario->Controls->Add(this->txt_usuario);
            this->panel_usuario->Location = System::Drawing::Point(35, 188);
            this->panel_usuario->Name = L"panel_usuario";
            this->panel_usuario->Size = System::Drawing::Size(270, 38);
            this->panel_usuario->TabIndex = 0;
            // 
            // lbl_icon_user
            // 
            this->lbl_icon_user->AutoSize = true;
            this->lbl_icon_user->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->lbl_icon_user->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
                static_cast<System::Int32>(static_cast<System::Byte>(140)));
            this->lbl_icon_user->Location = System::Drawing::Point(8, 9);
            this->lbl_icon_user->Name = L"lbl_icon_user";
            this->lbl_icon_user->Size = System::Drawing::Size(19, 20);
            this->lbl_icon_user->TabIndex = 0;
            this->lbl_icon_user->Text = L">";
            // 
            // txt_usuario
            // 
            this->txt_usuario->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->txt_usuario->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txt_usuario->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_usuario->ForeColor = System::Drawing::Color::White;
            this->txt_usuario->Location = System::Drawing::Point(32, 10);
            this->txt_usuario->Name = L"txt_usuario";
            this->txt_usuario->Size = System::Drawing::Size(230, 18);
            this->txt_usuario->TabIndex = 0;
            this->txt_usuario->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::txt_KeyDown);
            // 
            // lbl_contra
            // 
            this->lbl_contra->AutoSize = true;
            this->lbl_contra->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_contra->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(120)), static_cast<System::Int32>(static_cast<System::Byte>(120)),
                static_cast<System::Int32>(static_cast<System::Byte>(155)));
            this->lbl_contra->Location = System::Drawing::Point(35, 240);
            this->lbl_contra->Name = L"lbl_contra";
            this->lbl_contra->Size = System::Drawing::Size(81, 13);
            this->lbl_contra->TabIndex = 3;
            this->lbl_contra->Text = L"CONTRASEÑA";
            // 
            // panel_contra
            // 
            this->panel_contra->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->panel_contra->Controls->Add(this->lbl_icon_lock);
            this->panel_contra->Controls->Add(this->txt_contra);
            this->panel_contra->Location = System::Drawing::Point(35, 258);
            this->panel_contra->Name = L"panel_contra";
            this->panel_contra->Size = System::Drawing::Size(270, 38);
            this->panel_contra->TabIndex = 1;
            // 
            // lbl_icon_lock
            // 
            this->lbl_icon_lock->AutoSize = true;
            this->lbl_icon_lock->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11));
            this->lbl_icon_lock->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(100)),
                static_cast<System::Int32>(static_cast<System::Byte>(140)));
            this->lbl_icon_lock->Location = System::Drawing::Point(8, 9);
            this->lbl_icon_lock->Name = L"lbl_icon_lock";
            this->lbl_icon_lock->Size = System::Drawing::Size(15, 20);
            this->lbl_icon_lock->TabIndex = 0;
            this->lbl_icon_lock->Text = L"*";
            // 
            // txt_contra
            // 
            this->txt_contra->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->txt_contra->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->txt_contra->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->txt_contra->ForeColor = System::Drawing::Color::White;
            this->txt_contra->Location = System::Drawing::Point(32, 10);
            this->txt_contra->Name = L"txt_contra";
            this->txt_contra->Size = System::Drawing::Size(230, 18);
            this->txt_contra->TabIndex = 1;
            this->txt_contra->UseSystemPasswordChar = true;
            this->txt_contra->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::txt_KeyDown);
            // 
            // btn_acceso
            // 
            this->btn_acceso->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(122)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btn_acceso->Cursor = System::Windows::Forms::Cursors::Hand;
            this->btn_acceso->FlatAppearance->BorderSize = 0;
            this->btn_acceso->FlatAppearance->MouseOverBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
                static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(220)));
            this->btn_acceso->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btn_acceso->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btn_acceso->ForeColor = System::Drawing::Color::White;
            this->btn_acceso->Location = System::Drawing::Point(35, 318);
            this->btn_acceso->Name = L"btn_acceso";
            this->btn_acceso->Size = System::Drawing::Size(270, 42);
            this->btn_acceso->TabIndex = 2;
            this->btn_acceso->Text = L"Iniciar Sesión  ->";
            this->btn_acceso->UseVisualStyleBackColor = false;
            this->btn_acceso->Click += gcnew System::EventHandler(this, &Form1::btn_acceso_Click);
            // 
            // lbl_error
            // 
            this->lbl_error->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Bold));
            this->lbl_error->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(80)),
                static_cast<System::Int32>(static_cast<System::Byte>(80)));
            this->lbl_error->Location = System::Drawing::Point(35, 370);
            this->lbl_error->Name = L"lbl_error";
            this->lbl_error->Size = System::Drawing::Size(270, 20);
            this->lbl_error->TabIndex = 8;
            this->lbl_error->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            this->lbl_error->Visible = false;
            // 
            // Form1
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
                static_cast<System::Int32>(static_cast<System::Byte>(32)));
            this->ClientSize = System::Drawing::Size(340, 420);
            this->Controls->Add(this->lbl_error);
            this->Controls->Add(this->btn_acceso);
            this->Controls->Add(this->panel_contra);
            this->Controls->Add(this->lbl_contra);
            this->Controls->Add(this->panel_usuario);
            this->Controls->Add(this->lbl_usuario);
            this->Controls->Add(this->lbl_subtitulo);
            this->Controls->Add(this->lbl_titulo);
            this->Controls->Add(this->lbl_icono);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Name = L"Form1";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"UMG-MARKET Login";
            this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
            this->panel_usuario->ResumeLayout(false);
            this->panel_usuario->PerformLayout();
            this->panel_contra->ResumeLayout(false);
            this->panel_contra->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private: System::Void btn_acceso_Click(System::Object^ sender, System::EventArgs^ e)
    {
        // Validacion de campos vacios
        if (txt_usuario->Text->Trim() == L"" || txt_contra->Text->Trim() == L"")
        {
            MostrarError(L"Por favor complete todos los campos.");
            return;
        }

        // LOGIN REAL contra la base de datos
        bool isLogged = false;
        try
        {
            MySqlConnection^ con = gcnew MySqlConnection(connectionString);
            MySqlCommand^ cmd = gcnew MySqlCommand(
                "SELECT contrasenia FROM usuarios WHERE usuario=@u LIMIT 1", con);
            cmd->Parameters->AddWithValue("@u", txt_usuario->Text->Trim());

            con->Open();
            MySqlDataReader^ dr = cmd->ExecuteReader();

            if (dr->Read())
            {
                String^ contraBD = dr->IsDBNull(dr->GetOrdinal("contrasenia"))
                    ? "" : dr->GetString("contrasenia");

                if (contraBD == txt_contra->Text)
                    isLogged = true;
            }
            dr->Close();
            con->Close();
        }
        catch (Exception^ ex)
        {
            MostrarError(L"Error de conexi\u00F3n: " + ex->Message);
            return;
        }

        if (isLogged)
        {
            // Abrir dashboard y ocultar login
            contenidoForm = gcnew CppCLRWinFormsProject::contenido();
            contenidoForm->Show();
            contenidoForm->BringToFront();
            this->Hide();
        }
        else
        {
            MostrarError(L"Usuario o contrase\u00F1a incorrectos.");
            txt_contra->Clear();
            txt_contra->Focus();
        }
    }

           // Permite presionar Enter para iniciar sesion
    private: System::Void txt_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e)
    {
        if (e->KeyCode == System::Windows::Forms::Keys::Return)
            btn_acceso_Click(sender, System::EventArgs::Empty);
    }

    private: void MostrarError(String^ mensaje)
    {
        lbl_error->Text = mensaje;
        lbl_error->Visible = true;
    }

    private: System::Void Form1_Load(System::Object^ sender, System::EventArgs^ e) {}
    private: System::Void lbl_titulo_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}