// Copyright New Dawn Group LTD 2023. All Rights Reserved.


#include "AbilitySystem/Data/AuraAttributeInfo.h"

FAuraAttributeInfoStruct UAuraAttributeInfo::FindAttributeInfoForTag(const FGameplayTag& AttributeTag,
                                                                     bool bLogNotFound) const
{
	for (const FAuraAttributeInfoStruct& Info : AttributeInformation)
	{
		if (Info.AttributeTag.MatchesTagExact(AttributeTag)) return Info;
	}

	if (bLogNotFound)
	{
		UE_LOG(LogTemp, Error, TEXT("Can't finde Info for Attribute [%s] on AttributeInfor [%s]."),
		       *AttributeTag.ToString(), *GetNameSafe(this));
	}

	return {};
}
