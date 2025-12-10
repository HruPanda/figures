#pragma once
#include <memory>
#include <vector>
#include <array>
#include <Figures.h>
#include <type_traits>
#include <utility>


namespace Figures {
	class GlScreen{
		struct triplet {
			std::array<float, 3> buf_;
			triplet() noexcept = default;
			constexpr triplet(Vector3D v) noexcept : buf_{ v.x, v.y, v.z } {}
			[[nodiscard]] constexpr const float* ptr() const noexcept { return buf_.data(); }
		};
		static_assert(std::is_trivial<triplet>::value);
		static constexpr int default_w = 640, default_h = 480;
		std::unique_ptr<void, void(*)(void*)> handle_{ nullptr, +[](void*) {} };
		std::vector<std::vector<triplet>> figures_{};
	public:
		GlScreen() : GlScreen(default_w, default_h) {}
		GlScreen(int w, int h);
		template<typename Vector3DIterator>
		void add(Vector3DIterator begin, Vector3DIterator end);
		void render();
		void exec();
	};
	template<typename Vector3DIterator>
	inline void GlScreen::add(Vector3DIterator begin, Vector3DIterator end) {
		static_assert(std::is_same_v<std::iterator_traits<Vector3DIterator>::value_type, Vector3D>,
			"Expecting an iterator to a container of Vector3Ds");
		static_assert(std::is_same_v<std::iterator_traits<Vector3DIterator>::iterator_category, std::random_access_iterator_tag>,
			"Iterator is expected to be of random access type");
		std::vector<triplet> vec;
		vec.reserve(std::distance(begin, end));
		std::copy(begin, end, std::back_inserter(vec));
		figures_.push_back(std::move(vec));
	}

	template <typename T>
	inline void draw(const T& x, GlScreen& screen) { screen.add(x.begin(), x.end()); }
}