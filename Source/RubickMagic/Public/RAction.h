// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "UObject/NoExportTypes.h"
#include "RAction.generated.h"

/**
 * 
 */
UCLASS()
class RUBICKMAGIC_API URAction : public UObject
{
	GENERATED_BODY()
protected:
	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer GrantTags;

	UPROPERTY(EditDefaultsOnly, Category="Tags")
	FGameplayTagContainer BlockedTags;

	bool bIsRunning;
public:
	UPROPERTY(EditDefaultsOnly, Category="Action")
	FGameplayTag GameplayTag;
	
	UFUNCTION(BlueprintCallable, Category="Action")
	bool IsRunning() const;

	UFUNCTION(BlueprintNativeEvent, Category="Action")
	bool CanStart(AActor* Instigator);

	UFUNCTION(BlueprintNativeEvent, Category="Action")
	void StartAction(AActor* Instigator);
	
	UFUNCTION(BlueprintNativeEvent, Category="Action")
	void StopAction(AActor* Instigator);

	UFUNCTION(BlueprintCallable, Category="Action")
	URActionComponent* GetOwningComponent();
};
