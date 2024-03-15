// REVERSED ENGINEERED RENDERUTILS FROM ALIEN SWARM'S TIER2

#include "tier2/renderutils.h"
#include "KeyValues.h"
#include "materialsystem/imaterialsystem.h"
#include "materialsystem/imaterial.h"
#include "tier1/callqueue.h"

// memdbgon must be the last include file in a .cpp file!!!
#include <tier0/memdbgon.h>

// other random stuff
static bool s_bMaterialsInitialized;
static IMaterial *s_pWireframe;
static IMaterial *s_pWireframeIgnoreZ;
static IMaterial *s_pVertexColor;
static IMaterial *s_pVertexColorIgnoreZ;

static void InitializeStandardMaterials()
{
	if (s_bMaterialsInitialized)
		return;

	s_bMaterialsInitialized = true;

	KeyValues* pWireFrames = new KeyValues("wireframe");
	pWireFrames->SetInt("$vertexcolor", 1);
	s_pWireframe = g_pMaterialSystem->CreateMaterial("__utilWireframe", pWireFrames);

	KeyValues* pWireFrames2 = new KeyValues("wireframe");
	pWireFrames2->SetInt("$vertexcolor", 1);
	pWireFrames2->SetInt("$vertexalpha", 1);
	pWireFrames2->SetInt("$ignorez", 1);
	s_pWireframeIgnoreZ = g_pMaterialSystem->CreateMaterial("__utilWireframeIgnoreZ", pWireFrames2);

	KeyValues* pUnlitGeneric = new KeyValues("unlitgeneric");
	pUnlitGeneric->SetInt("$vertexcolor", 1);
	pUnlitGeneric->SetInt("$vertexalpha", 1);
	s_pVertexColor = g_pMaterialSystem->CreateMaterial("__utilVertexColor", pUnlitGeneric);

	KeyValues* pUnlitGeneric2 = new KeyValues("unlitgeneric");
	pUnlitGeneric2->SetInt("$vertexcolor", 1);
	pUnlitGeneric2->SetInt("$vertexalpha", 1);
	pUnlitGeneric2->SetInt("$ignorez", 1);
	s_pVertexColorIgnoreZ = g_pMaterialSystem->CreateMaterial("__utilVertexColorIgnoreZ", pUnlitGeneric);
}

static void ShutdownStandardMaterials()
{
	if (s_bMaterialsInitialized)
	{
		s_bMaterialsInitialized = false;

		s_pWireframe->DecrementReferenceCount();
		s_pWireframe = NULL;

		s_pWireframeIgnoreZ->DecrementReferenceCount();
		s_pWireframeIgnoreZ = NULL;

		s_pVertexColor->DecrementReferenceCount();
		s_pVertexColor = NULL;

		s_pVertexColorIgnoreZ->DecrementReferenceCount();
		s_pVertexColorIgnoreZ = NULL;
	}
}

//TODO: actually decompile these. make sure to use no leaked code at all.

static void RenderSphereInternal(const Vector& vCenter, float flRadius, int nTheta, int nPhi, Color c, IMaterial* pMaterial, bool bInsideOut)
{
}


// Renders a wireframe sphere
void RenderWireframeSphere(const Vector& vCenter, float flRadius, int nTheta, int nPhi, Color c, bool bZBuffer)
{
}

// Renders a sphere
void RenderSphere(const Vector& vCenter, float flRadius, int nTheta, int nPhi, Color c, bool bZBuffer, bool bInsideOut = false)
{
	IMaterial* v7;

	InitializeStandardMaterials();
	v7 = s_pVertexColor;
	if (!bZBuffer)
		v7 = s_pVertexColorIgnoreZ;

	RenderSphereInternal(vCenter, flRadius, nTheta, nPhi, c, v7, bInsideOut);
}

void RenderSphere(const Vector& vCenter, float flRadius, int nTheta, int nPhi, Color c, IMaterial* pMaterial, bool bInsideOut = false)
{
	RenderSphereInternal(vCenter, flRadius, nTheta, nPhi, c, pMaterial, bInsideOut);
}

// Renders a wireframe box relative to an origin 
void RenderWireframeBox(const Vector& vOrigin, const QAngle& angles, const Vector& vMins, const Vector& vMaxs, Color c, bool bZBuffer)
{
}

// Renders a swept wireframe box
void RenderWireframeSweptBox(const Vector& vStart, const Vector& vEnd, const QAngle& angles, const Vector& vMins, const Vector& vMaxs, Color c, bool bZBuffer)
{
}

static void RenderBoxInternal(const Vector& vOrigin, const QAngle& angles, const Vector& vMins, const Vector& vMaxs, Color c, IMaterial* pMaterial, bool bInsideOut)
{
}

// Renders a solid box 
void RenderBox(const Vector& origin, const QAngle& angles, const Vector& mins, const Vector& maxs, Color c, bool bZBuffer, bool bInsideOut = false)
{
	IMaterial* v7;

	InitializeStandardMaterials();
	v7 = s_pVertexColor;
	if (!bZBuffer)
		v7 = s_pVertexColorIgnoreZ;

	RenderBoxInternal(origin, angles, mins, maxs, c, v7, bInsideOut);
}

void RenderBox(const Vector& origin, const QAngle& angles, const Vector& mins, const Vector& maxs, Color c, IMaterial* pMaterial, bool bInsideOut = false)
{
	RenderBoxInternal(origin, angles, mins, maxs, c, pMaterial, bInsideOut);
}

static void RenderAxesAtOrigin(const Vector& vOrigin, float flScale, bool bZBuffer)
{
	RenderAxes(vOrigin, flScale, bZBuffer);
}

static void RenderAxesWithTransform(const matrix3x4_t& transform, float flScale, bool bZBuffer)
{
	RenderAxes(transform, flScale, bZBuffer);
}

// Renders axes, red->x, green->y, blue->z (axis aligned)
void RenderAxes(const Vector& vOrigin, float flScale, bool bZBuffer)
{
}

void RenderAxes(const matrix3x4_t& transform, float flScale, bool bZBuffer)
{
}

// Render a line
void RenderLine(const Vector& v1, const Vector& v2, Color c, bool bZBuffer)
{
}

static void RenderTriangleInternal(const Vector& p1, const Vector& p2, const Vector& p3, Color c, IMaterial* pMaterial)
{
}

// Draws a triangle
void RenderTriangle(const Vector& p1, const Vector& p2, const Vector& p3, Color c, bool bZBuffer)
{
	IMaterial* v5;

	v5 = s_pVertexColor;
	if (!bZBuffer)
		v5 = s_pVertexColorIgnoreZ;

	RenderTriangleInternal(p1, p2, p3, c, v5);
}

void RenderTriangle(const Vector& p1, const Vector& p2, const Vector& p3, Color c, IMaterial* pMaterial)
{
	RenderTriangleInternal(p1, p2, p3, c, pMaterial);
}

// Draws a axis-aligned quad
void RenderQuad(IMaterial* pMaterial, float x, float y, float w, float h, float z, float s0, float t0, float s1, float t1, const Color& clr)
{
}

// Renders a screen space quad
void DrawScreenSpaceRectangle(IMaterial* pMaterial, int nDestX, int nDestY, int nWidth, int nHeight, float flSrcTextureX0, float flSrcTextureY0, float flSrcTextureX1, float flSrcTextureY1, int nSrcTextureWidth, int nSrcTextureHeight, void* pClientRenderable = NULL, int nXDice = 1, int nYDice = 1, float fDepth = 0.0)
{
}

// Renders a single polygon without texturing in normalized-device coordinate space (x, y in the range [-1,1], z = 0)
void DrawNDCSpaceUntexturedPolygon(IMaterial* pMaterial, int nVertexCount, Vector2D* pScreenSpaceCoordinates, void* pClientRenderable)
{
}