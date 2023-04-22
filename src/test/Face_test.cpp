#include <vector>
#include "TestHarness.h"
#include "../main/Face.h"
#include "../main/geometry_types.h"

class FaceTest {
public:
    static Coordinates testRotate3d(Face& face, const Coordinates& p, const Rotations& r) {
        return face.rotate3d(p, r);
    }

    static Coordinates testProspectiveProjection(Face& face, const Coordinates& p) {
        return face.prospectiveProjection(p);
    }
};

TEST(Face, Rotate3d)
{
    Rotations init_rotation{0, 0, 0};
    Face face(init_rotation, '#', 44, 160);
    Rotations rotation{0.5, 0.3, 0.2};
    Coordinates old_p{2, 3, 4};

    Coordinates new_p = FaceTest::testRotate3d(face, old_p, rotation);

    CHECK_DOUBLES_EQUAL(2.176, new_p.x, 0.1);
    CHECK_DOUBLES_EQUAL(4.202, new_p.y, 0.1);
    CHECK_DOUBLES_EQUAL(102.6, new_p.z, 0.1);
}

TEST(Face, ProspectiveProjection)
{
    Rotations init_rotation{0, 0, 0};
    Face face(init_rotation, '#', 44, 160);
    Coordinates p{5, -3, 10};

    Coordinates projected_p = FaceTest::testProspectiveProjection(face, p);

    CHECK_EQUAL(140, projected_p.x);
    CHECK_EQUAL(4, projected_p.y);
    CHECK_DOUBLES_EQUAL(0.1, projected_p.z, 1e-3);
}

TEST(Face, DrawFace)
{
    Rotations init_rotation{0, 0, 0};
    Face face(init_rotation, '#', 44, 160);
    std::vector<char> canvas_buffer(44 * 160, ' ');
    std::vector<float> depth_buffer(44 * 160, 0.0);
    Rotations rotation{0.5, 0.3, 0.2};

    face.draw(canvas_buffer, depth_buffer, rotation, 10);

    // Check if the canvas buffer is not empty after drawing
    bool is_empty = true;
    for (char c : canvas_buffer)
    {
        if (c != ' ')
        {
            is_empty = false;
            break;
        }
    }
    CHECK(!is_empty);
}
