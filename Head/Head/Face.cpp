#include "stdafx.h"
#include ".\Face.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>


CFace::CFace(void)
{
	//nbV = nbVt = nbF =0;
}

CFace::~CFace(void)
{
}

bool CFace::chargeFichier (char *nomFichier)
{
	const int TAILLE=2000;
	ifstream entree;
	char buffer[TAILLE];
	//int nbChamps;
	coord3D point3D;
	coord2D point2D;
	face    uneFace;
	this->tableF.clear();
	this->tableV.clear();
	this->tableVt.clear();
	this->tableVn.clear();

    entree.open(nomFichier);
	if (!entree.good())
		return false;

	while (!entree.eof())        {
		entree.getline(buffer, TAILLE);
		string chaine (buffer);
		string cas = chaine.substr(0,2);
		istringstream stringEntree (chaine);
		if (cas.compare("v ")==0)
		{
			stringEntree >> cas >> point3D.x >> point3D.y >> point3D.z;
			tableV.push_back (point3D);
			//nbV++;
		}
		else if (cas.compare("vn")==0)
		{
			stringEntree >> cas >> point3D.x >> point3D.y >> point3D.z;
			tableVn.push_back (point3D);
			//nbV++;
		}
		else if (cas.compare("vt")==0)
		{
			stringEntree >> cas >> point2D.x >> point2D.y;
			tableVt.push_back (point2D);
			//nbVt++;
		}
		else if (cas.compare("f ")==0)
		{
			char slash;
			
			uneFace.nb = -1;
			int index=0;

			// recherche nombre de faces 
			do {
					index = chaine.find(" ",index+1);
					uneFace.nb++;
			} while (index != string::npos);
			// Ajustement du nb de vertex / face dans le cas
			// ou il aurait un espace en trop en fin de chaine
			if (chaine.find(" ",chaine.length() -1) != string::npos)
				uneFace.nb--;

			// allocation du nombre de faces dans la table face
			uneFace.elt = new couple[uneFace.nb];

			// *********** 3 cas peuvent se presenter :
			// une liste de v
			// des couples de v/vt
			// des couples de v/vn/vt
			int nbSlash = -1;
			index=0;
			// recherche nombre de slash 
			do {
					index = chaine.find("/",index+1);
					nbSlash++;
			} while (index != string::npos);
			if (nbSlash == uneFace.nb)   this->typeFace = v_vt;
			if (nbSlash == 2*uneFace.nb) this->typeFace = v_vn_vt;
			if (nbSlash == 0)            this->typeFace = v;

			// Traitement du cas particulier du double slash, cad sans vn
			index = chaine.find("//",0);
			if (index != string::npos)
				this->typeFace = v_vn_vt2;
			
			switch (this->typeFace)
			{
			case v_vt:
				stringEntree >> cas;
				for (int i=0; i < uneFace.nb; i++)
				{
					stringEntree >> uneFace.elt[i].v >> slash >> uneFace.elt[i].vt;								     
				}
					break;
			case v_vn_vt:
				stringEntree >> cas;
				for (int i=0; i < uneFace.nb; i++)
				{
					stringEntree  >> uneFace.elt[i].v >> slash >> uneFace.elt[i].vn >> slash >> uneFace.elt[i].vt;
				}												     
				break;
			case v_vn_vt2:
				stringEntree >> cas;
				for (int i=0; i < uneFace.nb; i++)
				{
					stringEntree  >> uneFace.elt[i].v >> slash >> slash >> uneFace.elt[i].vt;
				/*	stringEntree  >> uneFace.elt[i].v;
					stringEntree.ignore(2);
					stringEntree  >> uneFace.elt[i].vt;*/

				}												     
				break;
			case v:
				stringEntree >> cas;
				for (int i=0; i < uneFace.nb; i++)
				{
					stringEntree >> uneFace.elt[i].v ; 
				}
				break;
			}
			
			tableF.push_back (uneFace);
			//nbF++;
		//	delete uneFace.elt ;
		} // fin face
		// ne rien faire autrement

        if (entree.eof ())
                        break;     
    } // fin while

    entree.close ();
	return true;
}
int CFace::nombreVertexParFace (int noFace)
{
	return this->tableF[noFace].nb;
}
coord3D CFace::donnePoint (int noFace, int noVertex)
{
	int noV  = this->tableF[noFace].elt[noVertex].v - 1;
	return this->tableV[noV];
}
coord2D CFace::donnePointVt (int noFace, int noVertex)
{
	int noVt  = this->tableF[noFace].elt[noVertex].vt - 1;
	return this->tableVt[noVt];
}
coord3D CFace::donneEmprise (coord3D *maxis,coord3D *minis )
{
	coord3D bary;
	minis->x  = minis->y  = minis->z  = 255;
	maxis->x  = maxis->y  = maxis->z  = -255;

	for (int noFace=0; noFace < this->tableF.size(); noFace++)
	{
		for (int noVertex=0; noVertex < this->tableF[noFace].nb; noVertex++)
		{
			int noV  = this->tableF[noFace].elt[noVertex].v - 1;
			if (noV < 0)
			{
				exit (-1);
			}
			maxis->x = max (maxis->x,  this->tableV[noV].x); 
			maxis->y = max (maxis->y,  this->tableV[noV].y); 
			maxis->z = max (maxis->z,  this->tableV[noV].z); 
			minis->x = min (minis->x,  this->tableV[noV].x); 
			minis->y = min (minis->y,  this->tableV[noV].y); 
			minis->z = min (minis->z,  this->tableV[noV].z); 
		}
	}
	bary.x = (maxis->x + minis->x) / 2;
	bary.y = (maxis->y + minis->y) / 2;
	bary.z = (maxis->z + minis->z) / 2;
	return bary;
}
int CFace::nombreV (void)
{
	return this->tableV.size();
}
int CFace::nombreVt (void)
{
	return this->tableVt.size();
}
int CFace::nombreVn (void)
{
	return this->tableVn.size();
}
int CFace::nombreFaces (void)
{
	return this->tableF.size();
}

