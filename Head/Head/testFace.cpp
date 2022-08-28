// Head.cpp : définit le point d'entrée pour l'application console.
//
#include "stdafx.h"
#include "Face.h"
#include <iostream>

using namespace std;

int main()
{
	// Création des objets & déclarations des variables
	CFace objet;
	int noFace = 0;
	int noVertex = 0;
	int nf = 0;
	int nv = 0;
	coord3D maxis;
	coord3D mini;

	bool status = objet.chargeFichier("tete.obj"); // charchement du fichier tete
	nf = objet.nombreFaces();
	cout<<"Nombres de faces = "<< nf<<endl;
	cout<<"Nombres de vertex = "<< nv<<endl;
	while(noFace < nf)
	{
		nv = objet.nombreVertexParFace(noFace);
		noVertex = 0;
		while(noVertex < nv)
		{
			coord3D point = objet.donnePoint(noFace, noVertex);
			cout<<point.x << " " << point.y << " " << point.z << " ";
			noVertex++;
		}
		noFace++;
	}

	coord3D centre = objet.donneEmprise(&maxis, &mini);
	
	// Affichage des points centraux, min & max

	cout << endl << "Centre" <<endl;
	cout << "X : "<< centre.x << endl;
	cout << "Y : "<< centre.y << endl;
	cout << "Z : "<< centre.z << endl;

	cout << "Maxi" << endl;
	cout << "X :" << maxis.x << endl;
	cout << "Y :" << maxis.y << endl;
	cout << "Z :" << maxis.z <<endl;

	cout << "Mini"<<endl;
	cout << "X : " << mini.x << endl;
	cout << "Y : "<< mini.y << endl;
	cout << "Z : "<< mini.z << endl;

	

	cout << "Une touche ..."<<endl;
	cin.ignore(1);
}