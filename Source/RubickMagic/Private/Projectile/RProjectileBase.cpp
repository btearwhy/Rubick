// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile/RProjectileBase.h"

#include "Components/AudioComponent.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
ARProjectileBase::ARProjectileBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SphereComponent = CreateDefaultSubobject<USphereComponent>("SphereComponent");
	RootComponent = SphereComponent;
	
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComponent");
	MovementComponent->bRotationFollowsVelocity= true;
	MovementComponent->bInitialVelocityInLocalSpace = true;
	MovementComponent->ProjectileGravityScale = 0.0f;
	MovementComponent->InitialSpeed = 8000;

	FlyAudioComponent = CreateDefaultSubobject<UAudioComponent>("FlyAudioComponent");
	ImpactAudioComponent = CreateDefaultSubobject<UAudioComponent>("ImpactAudioComponent");

	ParticleSystemComponent = CreateDefaultSubobject<UParticleSystemComponent>("ParticleSystemComponent");
	ParticleSystemComponent->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ARProjectileBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARProjectileBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

