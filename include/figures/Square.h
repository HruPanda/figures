#pragma once
#include <Vector3D.h>
#include <array>

namespace Figures {
	class Square final {
		std::array<Vector3D, 4> vert_;
	public:
		Square() noexcept = default;
		constexpr Square(Vector3D top_left, float side) noexcept : vert_{ get_values(top_left, side) } {}
		constexpr void set_values(Vector3D top_left, float side) noexcept { vert_ = get_values(top_left, side); }
		[[nodiscard]] constexpr auto begin() const noexcept { return vert_.begin(); }
		[[nodiscard]] constexpr auto end() const noexcept { return vert_.end(); }
	private:
		[[nodiscard]] static constexpr std::array<Vector3D, 4> get_values(Vector3D top_left, float side) noexcept {
			return { Vector3D{ top_left.x, top_left.y, 0.0f },
					 Vector3D{ top_left.x + side, top_left.y, 0.0f },
					 Vector3D{ top_left.x + side, top_left.y - side, 0.0f },
					 Vector3D{ top_left.x, top_left.y - side, 0.0f } };
		}
	};
	static_assert(std::is_trivial<Square>::value);
}