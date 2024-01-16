#include "Airport.h"

Airport::Airport() = default;

void Airport::updateCell(Cell& cell, const std::vector<std::vector<Cell>>& cells, const std::vector<Cell>& adjacentCells, int& totalSecurityBreaches, int& totalPassengers) {
    bool adjacentToIndustrialOrCommercial = false;
    bool adjacentToTerminalWithDelayedFlights = false;
    int waitingTime = 0;
    bool securityBreach = false;

    // Check if adjacent to industrial or commercial areas
    for (const auto& adjacentCell : adjacentCells) {
        if (adjacentCell.getType() == "I" || adjacentCell.getType() == "C") {
            adjacentToIndustrialOrCommercial = true;

            // Check if adjacent to terminal with delayed flights
            if (adjacentCell.hasDelayedFlights()) {
                adjacentToTerminalWithDelayedFlights = true;

                // Increase passenger waiting time
                waitingTime++;

                // If waiting time exceeds threshold, inform passengers and re-route if possible
                if (waitingTime > WAITING_TIME_THRESHOLD) {
                    cell.informPassengers("Delayed flights! Re-routing if possible.");
                    cell.reRoutePassengers();
                }
            }
        }
    }

    // Check if adjacent to security checkpoints
    for (const auto& adjacentCell : adjacentCells) {
        if (adjacentCell.getType() == "S") {
            // Check if adjacent to terminal with passengers
            if (adjacentCell.hasPassengers()) {
                // Perform security checks
                securityBreach = adjacentCell.performSecurityChecks();

                // If security breach, increase security breach count
                if (securityBreach) {
                    totalSecurityBreaches++;
                }
            }
        }
    }

    // Control passenger flow between terminals
    if (adjacentToIndustrialOrCommercial && adjacentToTerminalWithDelayedFlights) {
        // If there was a security breach, update the cell
        if (securityBreach) {
            cell.updateCell();
        }

        // Inform passengers and re-route if needed
        if (waitingTime > WAITING_TIME_THRESHOLD) {
            cell.informPassengers("Delayed flights! Re-routing if possible.");
            cell.reRoutePassengers();
        }
    }
}

