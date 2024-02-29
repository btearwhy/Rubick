// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/RActionComponent.h"

#include "RAction.h"

// Sets default values for this component's properties
URActionComponent::URActionComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void URActionComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void URActionComponent::AddAction(AActor* Instigator, TSubclassOf<URAction> ActionClass)
{
	if(!ensure(ActionClass))
	{
		return;
	}
	URAction* NewAction = NewObject<URAction>(this, ActionClass);
	if(ensure(NewAction))
	{
		Actions.Add(NewAction);
	}
}

void URActionComponent::RemoveAction(URAction* Action)
{
	if(ensure(Action) && !Action->IsRunning())
	{
		Actions.Remove(Action);
	}
}

bool URActionComponent::StartActionByTag(AActor* Instigator, FGameplayTag GameplayTag)
{
	for(URAction* Action:Actions)
	{
		if(Action->GameplayTag == GameplayTag && Action->CanStart(Instigator))
		{
			Action->StartAction(Instigator);
			return true;
		}
	}
	return false;
}

bool URActionComponent::StopActionByTag(AActor* Instigator, FGameplayTag GameplayTag)
{
	for(URAction* Action:Actions)
	{
		if(Action->GameplayTag == GameplayTag)
		{
			if(Action->IsRunning())
			{
				Action->StopAction(Instigator);
				return true;
			}
		}
	}
	return false;
}


// Called every frame
void URActionComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

