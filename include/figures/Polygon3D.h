#pragma once
#include <vector>
#include "Vector3D.h"

namespace Figures {
	struct Polygon3D final : public std::vector<Vector3D> {
		using std::vector<Vector3D>::vector;
	};
}