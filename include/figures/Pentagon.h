#pragma once
#include <Vector3D.h>
#include <array>

namespace Figures {
	class Pentagon final {
		std::array<Vector3D, 5> vert_;
	public:
		Pentagon() noexcept = default;
		constexpr Pentagon(Vector3D p1, Vector3D p2, Vector3D p3, Vector3D p4, Vector3D p5) noexcept : vert_{ p1, p2, p3, p4, p5 } {}
		constexpr void set_values(const std::array<Vector3D, 5>& vals) noexcept { vert_ = vals; }
		[[nodiscard]] constexpr auto begin() const noexcept { return vert_.begin(); }
		[[nodiscard]] constexpr auto end() const noexcept { return vert_.end(); }
	};
	static_assert(std::is_trivial<Pentagon>::value);
}