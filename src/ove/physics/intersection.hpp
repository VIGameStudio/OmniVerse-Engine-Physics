#pragma once

#include <ove/math/obb.hpp>
#include <ove/math/ray.hpp>

namespace ove
{
	namespace physics
	{
		template <typename R, core::u8 D>
		bool intersects(const math::ray_t<R, D>& r, const math::obb_t<R, D>& b, R& min, R& max)
		{
			const vec_t<R, D> irdir = 1.0 / r.direction;

			R tmp1 = (b.min.data[0] - r.origin.data[0]) * irdir.data[0];
			R tmp2 = (b.max.data[0] - r.origin.data[0]) * irdir.data[0];
			min = min(tmp1, tmp2);
			max = max(tmp1, tmp2);

			for (u8 i = 1; i < D; ++i)
			{
				tmp1 = (b.min.data[i] - r.origin.data[i]) * irdir.data[i];
				tmp2 = (b.max.data[i] - r.origin.data[i]) * irdir.data[i];

				min = max(min, min(tmp1, tmp2));
				max = min(max, max(tmp1, tmp2));
			}

			return tmax >= tmin;
		}
	}
}