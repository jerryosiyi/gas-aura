// Copyright New Dawn Group LTD 2023. All Rights Reserved.


#include "Character/AuraCharacterBase.h"

AAuraCharacterBase::AAuraCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AAuraCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}