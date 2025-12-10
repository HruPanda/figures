#pragma once
#include <Vector3D.h>
#include <array>

namespace Figures {
	class Rectangle final {
		std::array<Vector3D, 4> vert_;
	public:
		Rectangle() noexcept = default;
		constexpr Rectangle(Vector3D top_left, Vector3D bottom_right) noexcept : vert_{ get_values(top_left, bottom_right) } {}
		constexpr void set_values(Vector3D top_left, Vector3D bottom_right) noexcept {
			vert_ = get_values(top_left, bottom_right);
		}
		[[nodiscard]] constexpr auto begin() const noexcept { return vert_.begin(); }
		[[nodiscard]] constexpr auto end() const noexcept { return vert_.end(); }
	private:
		[[nodiscard]] static constexpr std::array<Vector3D, 4> get_values(Vector3D top_left, Vector3D bottom_right) noexcept {
			return { Vector3D{top_left.x, top_left.y, 0.0f},
					 Vector3D{bottom_right.x, top_left.y, 0.0f},
					 Vector3D{bottom_right.x, bottom_right.y, 0.0f},
					 Vector3D{top_left.x, bottom_right.y, 0.0}};
		}
	};
	static_assert(std::is_trivial<Rectangle>::value);
}