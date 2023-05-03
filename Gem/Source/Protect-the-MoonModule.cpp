
#include <AzCore/Memory/SystemAllocator.h>
#include <AzCore/Module/Module.h>

#include "Protect-the-MoonSystemComponent.h"

#include <Protect-the-Moon/Protect-the-MoonTypeIds.h>

namespace Protect_the_Moon
{
    class Protect_the_MoonModule
        : public AZ::Module
    {
    public:
        AZ_RTTI(Protect_the_MoonModule, Protect_the_MoonModuleTypeId, AZ::Module);
        AZ_CLASS_ALLOCATOR(Protect_the_MoonModule, AZ::SystemAllocator);

        Protect_the_MoonModule()
            : AZ::Module()
        {
            // Push results of [MyComponent]::CreateDescriptor() into m_descriptors here.
            m_descriptors.insert(m_descriptors.end(), {
                Protect_the_MoonSystemComponent::CreateDescriptor(),
            });
        }

        /**
         * Add required SystemComponents to the SystemEntity.
         */
        AZ::ComponentTypeList GetRequiredSystemComponents() const override
        {
            return AZ::ComponentTypeList{
                azrtti_typeid<Protect_the_MoonSystemComponent>(),
            };
        }
    };
}// namespace Protect_the_Moon

AZ_DECLARE_MODULE_CLASS(Gem_Protect_the_Moon, Protect_the_Moon::Protect_the_MoonModule)
