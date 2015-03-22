// Fill out your copyright notice in the Description page of Project Settings.
#pragma once
#include "DKGlobalTypes.generated.h"

USTRUCT()
struct DONKEYKONG_API FDKScoreLadder
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY()
		FString PlayerName;
	UPROPERTY()
		int32 PlayerScore;

	FDKScoreLadder()
	{};
	FDKScoreLadder(const FString& PlayerNameIn, int32 PlayerScoreIn)
		: PlayerName(PlayerNameIn),
		PlayerScore(PlayerScoreIn)
	{};

	inline bool operator<(const FDKScoreLadder& Other) const
	{
		return PlayerScore < Other.PlayerScore;
	}
	inline bool operator>(const FDKScoreLadder& Other) const
	{
		return PlayerScore > Other.PlayerScore;
	}
	inline bool operator==(const FDKScoreLadder& Other) const
	{
		return PlayerScore == Other.PlayerScore;
	}
};

struct FSaveSlot
{
public:
	FString SlotName;
	int32 UserIndex;

	FSaveSlot()
	{};

	FSaveSlot(const FString& SlotNameIn, int32 UserIndexIn)
		: SlotName(SlotNameIn),
		UserIndex(UserIndexIn)
	{};

	inline void operator=(const FSaveSlot& Other)
	{
		SlotName = Other.SlotName;
		UserIndex = Other.UserIndex;
	}
};

USTRUCT()
struct FSaveSlotNames
{
	GENERATED_USTRUCT_BODY()
public:
	static const FSaveSlot LadderBoardSlot;
};