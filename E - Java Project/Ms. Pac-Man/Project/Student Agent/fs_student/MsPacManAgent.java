package fs_student;

import game.controllers.PacManController;
import game.core.G;
import game.core.Game;
import java.util.*;

public class MsPacManAgent implements PacManController//, Constants
{
	public int getAction(Game game, long time)
	{
		int[] possibleDirs = game.getPossiblePacManDirs(true);

		//if (possibleDirs.length == 0) {
		//	return Game.DOWN; // Default to moving down if no other options available
		//}

		// Get the current position of Ms. Pac-Man
		int pacManLoc = game.getCurPacManLoc();

		// Get the position of the nearest pill or power pill
		int targetNode = getNearestPillOrPowerPill(game);

		// If there are no pills or power pills left, just move randomly
		if (targetNode == -1) {
			return possibleDirs[G.rnd.nextInt(possibleDirs.length)];
		}

		// Calculate the direction that moves Ms. Pac-Man closer to the target
		int nextDir = getNextDirectionTowardsTarget(game, pacManLoc, targetNode);

		// Return the next direction to move
		return nextDir;
	}


	public int getNearestPillOrPowerPill(Game game)
	{
		// Get all the indices of pills and power pills
		int[] pillIndices = game.getPillIndices();
		int[] powerPillIndices = game.getPowerPillIndices();

		// Combine pill and power pill indices into one array
		List<Integer> allPills = new ArrayList<Integer>();
		for (int pillIndex : pillIndices) {
			allPills.add(pillIndex);
		}
		for (int powerPillIndex : powerPillIndices) {
			allPills.add(powerPillIndex);
		}

		// If no pills or power pills left, return -1
		if (allPills.isEmpty()) {
			return -1;
		}

		// Get current position of Ms. Pac-Man
		int pacManLoc = game.getCurPacManLoc();

		// Find the nearest pill or power pill to Ms. Pac-Man
		int nearestPill = allPills.get(0);
		int minDistance = game.getPathDistance(pacManLoc, nearestPill);
		for (int pill : allPills) {
			int distance = game.getPathDistance(pacManLoc, pill);
			if (distance < minDistance) {
				minDistance = distance;
				nearestPill = pill;
			}
		}

		// Return the index of the nearest pill or power pill
		return nearestPill;
	}

	public int getNextDirectionTowardsTarget(Game game, int currentLoc, int targetNode)
	{
		// Get possible directions from current location
		int[] possibleDirs = game.getPossiblePacManDirs(false); // Exclude reverse direction

		// Calculate distances to target node for each possible direction
		Map<Integer, Integer> dirDistances = new HashMap<Integer, Integer>();
		for (int dir : possibleDirs) {
			int nextLoc = game.getNeighbour(currentLoc, dir);
			int distance = game.getPathDistance(nextLoc, targetNode);
			dirDistances.put(dir, distance);
		}

		// Sort directions by distance to target node
		List<Map.Entry<Integer, Integer>> sortedDirs = new ArrayList<Map.Entry<Integer, Integer>>(dirDistances.entrySet());
		Collections.sort(sortedDirs, new Comparator<Map.Entry<Integer, Integer>>() {
			public int compare(Map.Entry<Integer, Integer> o1, Map.Entry<Integer, Integer> o2) {
				return o1.getValue().compareTo(o2.getValue());
			}
		});

		// Return the direction with the shortest distance to target node
		return sortedDirs.get(0).getKey();
	}
}