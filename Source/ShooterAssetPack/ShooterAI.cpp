// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"
#include "Kismet/GameplayStatics.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();
	
}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

	if(LineOfSightTo(playerPawn))
	{
		SetFocus(playerPawn);
		MoveToActor(playerPawn, AcceptanceRadius);
	}
	else
	{
		ClearFocus(EAIFocusPriority::Gameplay);
		StopMovement();
	}

}