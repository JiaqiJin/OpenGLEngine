#include "Transform.h"

namespace Kawaii::Transform
{
	namespace
	{
		Utils::vector<Math::Vec3> positions;
		Utils::vector<Math::Vec4> rotations;
		Utils::vector<Math::Vec3> scales;
	}

	Transform::Component Create_Transform(const InitInfo& info, Entity::Entity entity)
	{
		assert(entity.IsValid());
		const Id::id_type entityIndex{ Id::Index(entity.GetID()) };

		// If our entity has filled a hole in the vector of entities, put the
		// transform component into that same slot in the vector of transforms
		if (positions.size() > entityIndex)
		{
#ifdef _WIN64
			positions[entityIndex] = Math::Vec3(info.position);
			rotations[entityIndex] = Math::Vec4(info.rotation);
			scales[entityIndex] = Math::Vec3(info.scale);
#endif
		}
		else // If not, place it in the back with our entity
		{
			assert(positions.size() == entityIndex);
#ifdef _WIN64
			positions.emplace_back(info.position);
			rotations.emplace_back(info.rotation);
			scales.emplace_back(info.scale);
#endif
		}

		return Component{ transform_id{ entity.GetID() } };
	}

	void Remove_Transform(Component component)
	{
		assert(component.IsValid());
	}

	// Transform class method implementaions
	Math::Vec3 Component::Position() const
	{
		assert(IsValid());
		return positions[Id::Index(m_id)];
	}

	Math::Vec4 Component::Rotation() const
	{
		assert(IsValid());
		return rotations[Id::Index(m_id)];
	}

	Math::Vec3 Component::Scale() const
	{
		assert(IsValid());
		return scales[Id::Index(m_id)];
	}
}