#pragma once
namespace Figures {
	struct Vector3D final {
		float x, y, z;
	};
	static_assert(std::is_trivial<Vector3D>::value);
}