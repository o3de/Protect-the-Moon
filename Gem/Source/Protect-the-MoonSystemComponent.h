
#pragma once

#include <AzCore/Component/Component.h>

#include <Protect-the-Moon/Protect-the-MoonBus.h>

namespace Protect_the_Moon
{
    class Protect_the_MoonSystemComponent
        : public AZ::Component
        , protected Protect_the_MoonRequestBus::Handler
    {
    public:
        AZ_COMPONENT_DECL(Protect_the_MoonSystemComponent);

        static void Reflect(AZ::ReflectContext* context);

        static void GetProvidedServices(AZ::ComponentDescriptor::DependencyArrayType& provided);
        static void GetIncompatibleServices(AZ::ComponentDescriptor::DependencyArrayType& incompatible);
        static void GetRequiredServices(AZ::ComponentDescriptor::DependencyArrayType& required);
        static void GetDependentServices(AZ::ComponentDescriptor::DependencyArrayType& dependent);

        Protect_the_MoonSystemComponent();
        ~Protect_the_MoonSystemComponent();

    protected:
        ////////////////////////////////////////////////////////////////////////
        // Protect_the_MoonRequestBus interface implementation

        ////////////////////////////////////////////////////////////////////////

        ////////////////////////////////////////////////////////////////////////
        // AZ::Component interface implementation
        void Init() override;
        void Activate() override;
        void Deactivate() override;
        ////////////////////////////////////////////////////////////////////////
    };
}
