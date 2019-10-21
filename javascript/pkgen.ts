// Given an array of existing primary keys, find the lowest positive integer not in the list and return it. This is in active use on my Discord bot (legowerewolf/discordbot.ts)

pkgen(primaryKeys: Array<number>): number {
		return primaryKeys.reduce((accum, curr) => {
			return accum == curr ? curr + 1 : accum;
		}, 1);
	}
