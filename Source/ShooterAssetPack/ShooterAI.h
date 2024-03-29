// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "ShooterAI.generated.h"

/**
 * 
 */
UCLASS()
class SHOOTERASSETPACK_API AShooterAI : public AAIController
{
	GENERATED_BODY()

public:
	virtual void Tick(float DeltaTime) override;
	bool isDead() const;

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere)
	float AcceptanceRadius = 200;

	UPROPERTY(EditAnywhere)
	class UBehaviorTree* AIBehavior;
};
