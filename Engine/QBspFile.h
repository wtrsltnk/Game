#ifndef QBSPFILE
#define QBSPFILE

#include "BspTypes.h"

// This is our integer vector structure
struct tVector3i
{
	int x, y, z;				// The x y and z position of our integer vector
};


// This is our BSP header structure
struct tBSPHeader
{
    char strID[4];				// This should always be 'IBSP'
    int version;				// This should be 0x2e for Quake 3 files
}; 


// This is our BSP lump structure
struct tBSPLump
{
	int offset;					// The offset into the file for the start of this lump
	int length;					// The length in bytes for this lump
};


// This is our BSP vertex structure
struct tBSPVertex
{
    CVector3 vPosition;			// (x, y, z) position. 
    CVector2 vTextureCoord;		// (u, v) texture coordinate
    CVector2 vLightmapCoord;	// (u, v) lightmap coordinate
    CVector3 vNormal;			// (x, y, z) normal vector
    byte color[4];				// RGBA color for the vertex 
};


// This is our BSP face structure
struct tBSPFace
{
    int textureID;				// The index into the texture array 
    int effect;					// The index for the effects (or -1 = n/a) 
    int type;					// 1=polygon, 2=patch, 3=mesh, 4=billboard 
    int startVertIndex;			// The starting index into this face's first vertex 
    int numOfVerts;				// The number of vertices for this face 
    int meshVertIndex;			// The index into the first meshvertex 
    int numMeshVerts;			// The number of mesh vertices 
    int lightmapID;				// The texture index for the lightmap 
    int lMapCorner[2];			// The face's lightmap corner in the image 
    int lMapSize[2];			// The size of the lightmap section 
    CVector3 lMapPos;			// The 3D origin of lightmap. 
    CVector3 lMapVecs[2];		// The 3D space for s and t unit vectors. 
    CVector3 vNormal;			// The face normal. 
    int size[2];				// The bezier patch dimensions. 
};


// This is our BSP texture structure
struct tBSPTexture
{
    char strName[64];			// The name of the texture w/o the extension 
    int flags;					// The surface flags (unknown) 
    int contents;				// The content flags (unknown)
};


// This is our lumps enumeration
enum eLumps
{
    kEntities = 0,				// Stores player/object positions, etc...
    kTextures,					// Stores texture information
    kPlanes,				    // Stores the splitting planes
    kNodes,						// Stores the BSP nodes
    kLeafs,						// Stores the leafs of the nodes
    kLeafFaces,					// Stores the leaf's indices into the faces
    kLeafBrushes,				// Stores the leaf's indices into the brushes
    kModels,					// Stores the info of world models
    kBrushes,					// Stores the brushes info (for collision)
    kBrushSides,				// Stores the brush surfaces info
    kVertices,					// Stores the level vertices
    kMeshVerts,					// Stores the model vertices offsets
    kShaders,					// Stores the shader files (blending, anims..)
    kFaces,						// Stores the faces for the level
    kLightmaps,					// Stores the lightmaps for the level
    kLightVolumes,				// Stores extra world lighting information
    kVisData,					// Stores PVS and cluster info (visibility)
    kMaxLumps					// A constant to store the number of lumps
};

#include "BitSet.h"

#endif