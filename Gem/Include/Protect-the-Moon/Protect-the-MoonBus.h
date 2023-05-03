
#pragma once

#include <Protect-the-Moon/Protect-the-MoonTypeIds.h>

#include <AzCore/EBus/EBus.h>
#include <AzCore/Interface/Interface.h>

namespace Protect_the_Moon
{
    class Protect_the_MoonRequests
    {
    public:
        AZ_RTTI(Protect_the_MoonRequests, Protect_the_MoonRequestsTypeId);
        virtual ~Protect_the_MoonRequests() = default;
        // Put your public methods here
    };

    class Protect_the_MoonBusTraits
        : public AZ::EBusTraits
    {
    public:
        //////////////////////////////////////////////////////////////////////////
        // EBusTraits overrides
        static constexpr AZ::EBusHandlerPolicy HandlerPolicy = AZ::EBusHandlerPolicy::Single;
        static constexpr AZ::EBusAddressPolicy AddressPolicy = AZ::EBusAddressPolicy::Single;
        //////////////////////////////////////////////////////////////////////////
    };

    using Protect_the_MoonRequestBus = AZ::EBus<Protect_the_MoonRequests, Protect_the_MoonBusTraits>;
    using Protect_the_MoonInterface = AZ::Interface<Protect_the_MoonRequests>;

} // namespace Protect_the_Moon
