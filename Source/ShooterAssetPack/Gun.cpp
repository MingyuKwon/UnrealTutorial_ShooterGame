// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"


// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	RootComponent = Root;

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Skeletal Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGun::PullTrigger()
{
	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
	

	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) return;

	AController* OwnerController = OwnerPawn->GetController();
	if (OwnerController == nullptr) return;

	FVector out_Location;
	FRotator out_Rotation;

	OwnerController->GetPlayerViewPoint(out_Location, out_Rotation);

	FVector End = out_Location + out_Rotation.Vector() * MaxRange;
	FHitResult hit;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	params.AddIgnoredActor(GetOwner());

	
	if (GetWorld()->LineTraceSingleByChannel(hit, out_Location, End, ECollisionChannel::ECC_GameTraceChannel1, params))
	{
		FVector ShotDirection = -out_Rotation.Vector();
		UGameplayStatics::SpawnEmitterAtLocation(this, HitFlash, hit.ImpactPoint);
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), HitSound, hit.ImpactPoint);

		AActor* hittedActor = hit.GetActor();
		if (hittedActor)
		{
			FPointDamageEvent DamageEvent(Damage, hit, ShotDirection, nullptr);
			hittedActor->TakeDamage(Damage, DamageEvent, OwnerController, this);
		}
	}


}

