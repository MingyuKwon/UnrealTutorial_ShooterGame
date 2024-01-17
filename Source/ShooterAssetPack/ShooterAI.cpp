// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAI.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void AShooterAI::BeginPlay()
{
	Super::BeginPlay();
	if (AIBehavior)
	{
		RunBehaviorTree(AIBehavior);
		APawn* playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		GetBlackboardComponent()->SetValueAsVector(TEXT("PlayerLocation"), playerPawn->GetActorLocation());
		GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
		
	}
	
}

void AShooterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}