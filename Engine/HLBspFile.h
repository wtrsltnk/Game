#ifndef HLBSPFILE
#define HLBSPFILE

#define BSPVERSION   30

// This is our BSP header structure
struct hlBSPHeader_t
{
   int      version;
};

// This is our BSP lump structure
struct hlBSPLump_t
{
	int offset;					// The offset into the file for the start of this lump
	int length;					// The length in bytes for this lump
};

// This is our BSP vertex structure
struct hlBSPVertex_t
{
   float point[3];
};

// This is our BSP edge structure
struct hlBSPEdge_t
{
   unsigned short v[2];			// vertex numbers
};

// This is our BSP face structure
struct hlBSPFace_t
{
   short    planenum;
   short    side;

   int      firstedge;			// we must support > 64k edges
   short    numedges;
   short    texinfo;

   byte     styles[4];
   int      lightofs;			// start of [numstyles*surfsize] samples
};

// This is our lumps enumeration
enum eHlLumps
{
	hlEntities = 0,
	hlPlanes,
	hlTextures,
	hlVertexes,
	hlVisibility,
	hlNodes,
	hlTexInfo,
	hlFaces,
	hlLighting,
	hlClipNode,
	hlLeafs,
	hlMarkSurface,
	hlEdges,
	hlSurfEdges,
	hlModels,
	hlMaxLumps
};

#include "BitSet.h"

#endif