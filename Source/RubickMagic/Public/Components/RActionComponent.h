// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "Components/ActorComponent.h"
#include "RActionComponent.generated.h"


class URAction;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class RUBICKMAGIC_API URActionComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	URActionComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY()
	TArray<URAction*> Actions;

	UPROPERTY(EditAnywhere, Category="Actions")
	TArray<URAction*> DefaultActions;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	FGameplayTagContainer ActiveGameplayTags;
	
	UFUNCTION(BlueprintCallable, Category="Actions")
	void AddAction(AActor* Instigator, TSubclassOf<URAction> ActionClass);

	UFUNCTION(BlueprintCallable, Category="Actions")
	void RemoveAction(URAction* Action);

	UFUNCTION(BlueprintCallable, Category="Actions")
	bool StartActionByTag(AActor* Instigator, FGameplayTag GameplayTag);

	UFUNCTION(BlueprintCallable, Category="Actions")
	bool StopActionByTag(AActor* Instigator, FGameplayTag GameplayTag);		
};
