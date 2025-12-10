#pragma once
#include <Vector3D.h>
#include <array>

namespace Figures {
	class Triangle final {
		std::array<Vector3D, 3> vert_;
	public:
		Triangle() noexcept = default;
		constexpr Triangle(Vector3D p1, Vector3D p2, Vector3D p3) noexcept : vert_{p1,p2,p3} {}
		constexpr void set_values(Vector3D p1, Vector3D p2, Vector3D p3) noexcept {
			vert_ = { p1, p2, p3 };
		}
		[[nodiscard]] constexpr auto begin() const noexcept { return vert_.begin(); }
		[[nodiscard]] constexpr auto end() const noexcept { return vert_.end(); }
	};
	static_assert(std::is_trivial<Triangle>::value);
}