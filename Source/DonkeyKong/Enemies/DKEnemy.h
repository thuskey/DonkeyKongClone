// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "DKEnemy.generated.h"

UCLASS()
class DONKEYKONG_API ADKEnemy : public APawn
{
	GENERATED_BODY()
protected:
	/* Base collision sphere. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Collision")
		USphereComponent* Collision;
	/* Visual representation of enemy. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Visuals")
		UStaticMeshComponent* Mesh;

protected:
	/* Chance that enemy will climb on ladder 0 - never, 1 - always */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Config")
		float ChanceToClimb;

	/* Score which player will be awarded for successfully jumping over. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Score")
		int32 ScoreForJumping;

public:
	// Sets default values for this actor's properties
	ADKEnemy();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaSeconds) override;

	/* Call to tell enemy to climb up */
	virtual void ClimbUp() {};

	/* Call to tell enemey to climb down */
	virtual void ClimbDown() {};

	/* Call when enemy should stop climbing and leave ladder. */
	virtual void ClimbStop() {};

	inline float GetChanceToClimb() { return ChanceToClimb; }

public:
	inline int32 GetScoreForJumping() { return ScoreForJumping; }
};