// Fill out your copyright notice in the Description page of Project Settings.


#include "RAction.h"

#include "Components/RActionComponent.h"

bool URAction::IsRunning() const
{
	return bIsRunning;
}

URActionComponent* URAction::GetOwningComponent()
{
	return Cast<URActionComponent>(GetOuter());
}


bool URAction::CanStart_Implementation(AActor* Instigator)
{
	if(IsRunning())
	{
		return false;
	}
	const URActionComponent* ActionComponent = GetOwningComponent();
	if(ActionComponent->ActiveGameplayTags.HasAny(BlockedTags))
	{
		return false;
	}
	return true;
}

void URAction::StartAction_Implementation(AActor* Instigator)
{
	URActionComponent* ActionComponent = GetOwningComponent();
	ActionComponent->ActiveGameplayTags.AppendTags(GrantTags);
	bIsRunning = true;
}

void URAction::StopAction_Implementation(AActor* Instigator)
{
	ensureAlways(bIsRunning);
	URActionComponent* ActionComponent = GetOwningComponent();
	ActionComponent->ActiveGameplayTags.RemoveTags(GrantTags);
	bIsRunning = false;
}
