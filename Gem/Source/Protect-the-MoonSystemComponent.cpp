
#include <AzCore/Serialization/SerializeContext.h>

#include "Protect-the-MoonSystemComponent.h"

#include <Protect-the-Moon/Protect-the-MoonTypeIds.h>

namespace Protect_the_Moon
{
    AZ_COMPONENT_IMPL(Protect_the_MoonSystemComponent, "Protect_the_MoonSystemComponent",
        Protect_the_MoonSystemComponentTypeId);

    void Protect_the_MoonSystemComponent::Reflect(AZ::ReflectContext* context)
    {
        if (auto serializeContext = azrtti_cast<AZ::SerializeContext*>(context))
        {
            serializeContext->Class<Protect_the_MoonSystemComponent, AZ::Component>()
                ->Version(0)
                ;
        }
    }

    void Protect_the_MoonSystemComponent::GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided)
    {
        provided.push_back(AZ_CRC_CE("Protect_the_MoonService"));
    }

    void Protect_the_MoonSystemComponent::GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible)
    {
        incompatible.push_back(AZ_CRC_CE("Protect_the_MoonService"));
    }

    void Protect_the_MoonSystemComponent::GetRequiredServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& required)
    {
    }

    void Protect_the_MoonSystemComponent::GetDependentServices([[maybe_unused]] AZ::ComponentDescriptor::DependencyArrayType& dependent)
    {
    }

    Protect_the_MoonSystemComponent::Protect_the_MoonSystemComponent()
    {
        if (Protect_the_MoonInterface::Get() == nullptr)
        {
            Protect_the_MoonInterface::Register(this);
        }
    }

    Protect_the_MoonSystemComponent::~Protect_the_MoonSystemComponent()
    {
        if (Protect_the_MoonInterface::Get() == this)
        {
            Protect_the_MoonInterface::Unregister(this);
        }
    }

    void Protect_the_MoonSystemComponent::Init()
    {
    }

    void Protect_the_MoonSystemComponent::Activate()
    {
        Protect_the_MoonRequestBus::Handler::BusConnect();
    }

    void Protect_the_MoonSystemComponent::Deactivate()
    {
        Protect_the_MoonRequestBus::Handler::BusDisconnect();
    }
}
