// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RProjectileBase.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UCLASS()
class RUBICKMAGIC_API ARProjectileBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARProjectileBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component")
	USphereComponent* SphereComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component")
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component")
	UParticleSystemComponent* ParticleSystemComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component")
	UAudioComponent* FlyAudioComponent;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Component")
	UAudioComponent* ImpactAudioComponent;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	UParticleSystem* LaunchVFX;

	UPROPERTY(EditDefaultsOnly, Category="Effects")
	UParticleSystem* ImpactVFX;
	
	UPROPERTY(EditDefaultsOnly, Category="Property")
	float Duration;
	
	UPROPERTY(EditDefaultsOnly, Category="Damage")
	float Damage;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
