#include "bbox.h"
#include "Point.h"
#include <vector>


using namespace std;

class OctreeNode {
  public:
    //CAN PUT ANY SEARCH OR OTHER NECESSARY FUNCTION HERE.

    OctreeNode(vector<Point> points, int depth, OctreeNode *Parent, BBox NodeBB, int maxDepth);   //OctreeNode* root; ///< root node of the OT
    OctreeNode(int depth, BBox NodeBB, int maxDepth); //this should just return a full octree of the maxDepth provided. No
    //need to define initial BBox size
    OctreeNode* get_root() const { return root; }

    /**
    * Draw the BVH with OpenGL - used in visualizer
    */
    void draw(const Color& c) const { }
    void draw(OctreeNode *node, const Color& c) const;

    /**
    * Draw the BVH outline with OpenGL - used in visualizer
    */
    void drawOutline(const Color& c) const { }
    void drawOutline(OctreeNode *node, const Color& c) const;

    //OctreeNode *construct_ot(const std::vector<Vector3D> points, size_t max_depth);
    BBox NodeBB; // this has max, min, and extent members
    vector<OctreeNode> Children;
    OctreeNode *Parent; // optional
    vector<Point> nodePoints; //POINT CLASS
    CGL::Vector3D     Center;
    CGL::Vector3D     HalfSize;
    bool         IsLeaf;
    bool hasChildren;
    int maxDepth;
    int depth;
};
