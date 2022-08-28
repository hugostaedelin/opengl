#pragma once
#include <vector>
using namespace std;

enum genreFace {v,v_vt,v_vn_vt,v_vn_vt2};

struct coord2D {
	double x;
	double y;
};

struct coord3D {
	double x;
	double y;
	double z;
};
struct couple {
	int v;
	int vn;
	int vt;
};

struct face {
	int nb;
	couple  *elt;
};
class CFace
{
private:
	vector <coord3D> tableV;
	vector <coord2D> tableVt;
	vector <coord3D> tableVn;
	vector <face>    tableF;
	genreFace typeFace;
public:
	CFace(void);
	bool chargeFichier (char *nomFichier);
	int nombreV (void);
	int nombreVt (void);
	int nombreVn (void);
	int nombreFaces (void);
	int nombreVertexParFace (int noFace); 
	coord3D donnePoint (int noFace, int noVertex); 
	coord2D donnePointVt (int noFace, int noVertex); 
	coord3D donneEmprise (coord3D *maxis,coord3D *mini); 
	
	~CFace(void);
};
