#include <windows.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include "Face.h"
#pragma once

namespace TutoOpenGL {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Description résumée de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ajoutez ici le code du constructeur
			//
			angle = 0;
			width = 640;
			height = 480;
			m_hDC = GetDC ( (HWND)this->Handle.ToPointer());
			InitPixelFormat(m_hDC);
			ReSizeGLScene(width, height);
			InitGL();
			objet = new CFace();
		}

	protected:
		/// <summary>
		/// Nettoyage des ressources utilisées.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  fichierToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  quitterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
	private: System::Windows::Forms::ToolStripMenuItem^  aProposToolStripMenuItem;
	private: System::ComponentModel::IContainer^  components;
	protected: 

	private:
		/// <summary>
		/// Variable nécessaire au concepteur.
		/// </summary>

		HDC m_hDC;
		HGLRC m_hglrc;
		GLsizei width;
		GLsizei height;
		private: System::Windows::Forms::Timer^  timer1;
		private: System::Windows::Forms::Button^  button1;
		GLfloat angle;
		CFace* objet;
	private: System::Windows::Forms::HScrollBar^  hScrollBar1;
	private: System::Windows::Forms::HScrollBar^  hScrollBar2;
	private: System::Windows::Forms::HScrollBar^  hScrollBar3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;

			 int nbFaces;

#pragma region Windows Form Designer generated code
			 /// <summary>
			 /// Méthode requise pour la prise en charge du concepteur - ne modifiez pas
			 /// le contenu de cette méthode avec l'éditeur de code.
			 /// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->fichierToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->quitterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->aProposToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->hScrollBar1 = (gcnew System::Windows::Forms::HScrollBar());
				 this->hScrollBar2 = (gcnew System::Windows::Forms::HScrollBar());
				 this->hScrollBar3 = (gcnew System::Windows::Forms::HScrollBar());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->menuStrip1->SuspendLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
				 this->SuspendLayout();
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->fichierToolStripMenuItem, 
					 this->toolStripMenuItem1});
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Size = System::Drawing::Size(660, 24);
				 this->menuStrip1->TabIndex = 0;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // fichierToolStripMenuItem
				 // 
				 this->fichierToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->quitterToolStripMenuItem});
				 this->fichierToolStripMenuItem->Name = L"fichierToolStripMenuItem";
				 this->fichierToolStripMenuItem->Size = System::Drawing::Size(37, 20);
				 this->fichierToolStripMenuItem->Text = L"File";
				 // 
				 // quitterToolStripMenuItem
				 // 
				 this->quitterToolStripMenuItem->Name = L"quitterToolStripMenuItem";
				 this->quitterToolStripMenuItem->Size = System::Drawing::Size(104, 22);
				 this->quitterToolStripMenuItem->Text = L"Leave";
				 this->quitterToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::quitterToolStripMenuItem_Click);
				 // 
				 // toolStripMenuItem1
				 // 
				 this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) {this->aProposToolStripMenuItem});
				 this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
				 this->toolStripMenuItem1->Size = System::Drawing::Size(24, 20);
				 this->toolStripMenuItem1->Text = L"\?";
				 // 
				 // aProposToolStripMenuItem
				 // 
				 this->aProposToolStripMenuItem->Name = L"aProposToolStripMenuItem";
				 this->aProposToolStripMenuItem->Size = System::Drawing::Size(107, 22);
				 this->aProposToolStripMenuItem->Text = L"About";
				 this->aProposToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::aProposToolStripMenuItem_Click);
				 // 
				 // timer1
				 // 
				 this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(12, 27);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(45, 23);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"Load";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
				 // 
				 // hScrollBar1
				 // 
				 this->hScrollBar1->Location = System::Drawing::Point(43, 513);
				 this->hScrollBar1->Maximum = 255;
				 this->hScrollBar1->Minimum = -255;
				 this->hScrollBar1->Name = L"hScrollBar1";
				 this->hScrollBar1->Size = System::Drawing::Size(87, 19);
				 this->hScrollBar1->TabIndex = 2;
				 this->hScrollBar1->Value = -1;
				 // 
				 // hScrollBar2
				 // 
				 this->hScrollBar2->Location = System::Drawing::Point(279, 513);
				 this->hScrollBar2->Maximum = 255;
				 this->hScrollBar2->Minimum = -255;
				 this->hScrollBar2->Name = L"hScrollBar2";
				 this->hScrollBar2->Size = System::Drawing::Size(87, 19);
				 this->hScrollBar2->TabIndex = 3;
				 // 
				 // hScrollBar3
				 // 
				 this->hScrollBar3->Location = System::Drawing::Point(527, 513);
				 this->hScrollBar3->Maximum = 255;
				 this->hScrollBar3->Minimum = -255;
				 this->hScrollBar3->Name = L"hScrollBar3";
				 this->hScrollBar3->Size = System::Drawing::Size(87, 19);
				 this->hScrollBar3->TabIndex = 4;
				 this->hScrollBar3->Value = 1;
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Location = System::Drawing::Point(12, 486);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(636, 60);
				 this->pictureBox1->TabIndex = 5;
				 this->pictureBox1->TabStop = false;
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(58, 500);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(55, 13);
				 this->label1->TabIndex = 6;
				 this->label1->Text = L"Edit X grid";
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(293, 500);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(55, 13);
				 this->label2->TabIndex = 7;
				 this->label2->Text = L"Edit Y grid";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(540, 500);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(55, 13);
				 this->label3->TabIndex = 8;
				 this->label3->Text = L"Edit Z grid";
				 // 
				 // MyForm
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::Control;
				 this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->ClientSize = System::Drawing::Size(660, 558);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->hScrollBar3);
				 this->Controls->Add(this->hScrollBar2);
				 this->Controls->Add(this->hScrollBar1);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->menuStrip1);
				 this->MainMenuStrip = this->menuStrip1;
				 this->Name = L"MyForm";
				 this->Text = L"3D Head with OpenGL";
				 this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }

			 void InitPixelFormat (HDC hDC)
			 {
				 static PIXELFORMATDESCRIPTOR pfd =
				 {
					 sizeof(PIXELFORMATDESCRIPTOR), 1,PFD_SUPPORT_OPENGL | PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER,
					 PFD_TYPE_RGBA, 16,0, 0, 0, 0, 0, 0,0,0, 0,0, 0, 0, 0,32,0, 0, 0, 0, 0, 0,0
				 };
				 int pixelFormat = ChoosePixelFormat(hDC, &pfd);
				 if (!pixelFormat) return;
				 if (!SetPixelFormat(hDC, pixelFormat, &pfd)) return;
				 if ((m_hglrc = wglCreateContext(hDC)) == NULL) return;
				 if ((wglMakeCurrent(hDC, m_hglrc)) == NULL) return;
			 }

			 void ReSizeGLScene (int width, int height)
			 {
				 glViewport(0,0,width,height);
				 glMatrixMode(GL_PROJECTION);
				 glLoadIdentity();
				 gluPerspective(45.0f,(GLfloat)width/(GLfloat)height,0.1f,100.0f); glMatrixMode(GL_MODELVIEW);
				 glLoadIdentity();
			 }

			 void InitGL()
			 {
				 glShadeModel(GL_SMOOTH);
				 glClearColor(0.0f, 0.0f, 0.0f, 0.5f);
				 glClearDepth(1.0f);
				 glEnable(GL_DEPTH_TEST);
				 glDepthFunc(GL_LEQUAL);
				 glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
			 }

			 void Render()
			 {
				 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
				 glMatrixMode(GL_MODELVIEW);
				 glLoadIdentity();
				
#ifdef ACTIVITE1
				 //Placer ici tout le code de transformation et de dessin
				gluLookAt(0.1,1.2,5.1,0,0,0,0,1,0); // Activite 1
				 glRotatef(angle,1.0f,1.0f,1.0f); // Activite 1

				 GLdouble red[3] = {0.8, 0.0, 0.0 } ;
				 GLdouble gray[3] = {0.8, 0.8, 0.8 } ;
				 GLdouble purple[3] ={1.0, 0.14, 0.6667} ;
				 GLdouble green[3] = {0.0, 0.75, 0.0} ;
				 GLdouble yellow[3] = {0.75, 0.75, 0.14} ;
				 GLdouble blue[3] = {0, 0, 0.8} ;
				 GLdouble size = 0.5 ;
				 glLineWidth(0.10f);
				 // Draw the six faces of the cube.
				 
				 glColor3dv(red) ;
				 glBegin(GL_LINE_LOOP); // right
				 glVertex3d( size, size, size);
				 glVertex3d(-size, size, size);
				 glVertex3d(-size, -size, size);
				 glVertex3d( size, -size, size);
				 glEnd();
				 glColor3dv(green) ;
				 glBegin(GL_LINE_LOOP); //left
				 glVertex3d( size, size, -size);
				 glVertex3d( size, -size, -size);
				 glVertex3d(-size, -size, -size);
				 glVertex3d(-size, size, -size);
				 glEnd();
				 glColor3dv(purple) ;
				 glBegin(GL_LINE_LOOP); //Front
				 glVertex3d(-size, size, size);
				 glVertex3d(-size, size, -size);
				 glVertex3d(-size, -size, -size);
				 glVertex3d(-size, -size, size);
				 glEnd();
				 glColor3dv(yellow) ;
				 glBegin(GL_LINE_LOOP); //Back
				 glVertex3d(size, size, size);
				 glVertex3d(size, -size, size);
				 glVertex3d(size, -size, -size);
				 glVertex3d(size, size, -size);
				 glEnd();
				 glColor3dv(gray) ;
				 glBegin(GL_LINE_LOOP); //Top
				 glVertex3d(-size, size, -size);
				 glVertex3d(-size, size, size);
				 glVertex3d( size, size, size);
				 glVertex3d( size, size, -size);
				 glEnd();
				 glColor3dv(blue) ;
				 glBegin(GL_LINE_LOOP); //Bottom
				 glVertex3d(-size, -size, -size);
				 glVertex3d( size, -size, -size);
				 glVertex3d( size, -size, size);
				 glVertex3d(-size, -size, size);
				 glEnd();
#else

				 // Activite 2
				 GLdouble red[3] = {0.8, 0.0, 0.0 } ;
				 GLdouble green[3] = {0.0, 0.75, 0.0} ;
				 GLdouble yellow[3] = {0.75, 0.75, 0.14} ;
				 GLdouble blue[3] = {0, 0, 0.8} ;
				 GLdouble size = 0.5 ;

				 coord3D maxis;
				 coord3D mini;
				 coord3D centre = objet->donneEmprise(&maxis, &mini);
				 /*
				 glColor3dv(blue) ;
				 glBegin(GL_LINE_LOOP);
				 glVertex3d( centre.x,centre.y, centre.z);
				 glEnd();

				 glColor3dv(yellow) ;
				 glBegin(GL_LINE_LOOP);
				 glVertex3d( mini.x,mini.y, mini.z);
				 glEnd();
				 
				 glColor3dv(green) ;
				 glBegin(GL_LINE_LOOP);
				 glVertex3d( );
				 glEnd();
				 */
				 // Avec la methode Emprise

				 int x = this->hScrollBar1->Value;
				 int y = this->hScrollBar2->Value;
				 int z = this->hScrollBar3->Value;

				 gluLookAt(x, y ,z, // position de l'oeil (x, y, z)
				centre.x, centre.y, centre.z, // centre de l'objet observé (x y z)
							0		,1		,0);	// Projection Y

				 // Sans la methode Emprise
				/* 

				 gluLookAt(0.09 , 0.6 , -0.15, // position de l'oeil (x, y, z)
						  -0.05, 0.73 , 0.006, // centre de l'objet observé (x y z)
							0,		1,	 0); // Projection Y
				
				*/

				 glRotatef(angle, 0.00, 0.70, 0.006); // angle + centre de la rotation (xyz)
				 
				 glLineWidth(0.10f);
				 int noFace = 0;
				 int nf = objet->nombreFaces();

				 while(noFace < nf)
				 {
					 int nv = objet->nombreVertexParFace(noFace);
					 int noVertex = 0;
					 glColor3dv(red) ;
					 glBegin(GL_LINE_LOOP);
					 while(noVertex < nv)
					 {
						 coord3D point = objet->donnePoint(noFace, noVertex);
						 glVertex3d(point.x,point.y,point.z);
						 noVertex++;
					 }
					 glEnd();
					 noFace++;
				 }

				 
			 }
#endif			
			 
			 
#pragma endregion




	private: System::Void quitterToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)  {
				 Application::Exit();
			 }
	private: System::Void aProposToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 			 {
					 MessageBox::Show( "Modelisation 3D Staedelin Hugo.\nRealized with OpenGL\nVersion 1.9\nDate 08/01/2019\n","",
					 MessageBoxButtons::OK,
					 MessageBoxIcon::Asterisk); 
			 }


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) 
			 {
				 angle++;
				 Render();
				 SwapBuffers(m_hDC);
			 }

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
				
				 bool status = objet->chargeFichier("tete.obj");
				 if(status == false)
				 {
					 MessageBox::Show( "Error","",
					 MessageBoxButtons::OK,
					 MessageBoxIcon::Asterisk); 
				 }
				 timer1->Enabled=true;
				
			 }
	private: System::Void MyForm_Load(System::Object^  sender, System::EventArgs^  e) {
			 }

};
}
