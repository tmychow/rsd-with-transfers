"""
File: plotting.py
----------------
I couldn't figure out how to install matplotlib-cpp so we're using Python
"""
import matplotlib.pyplot as plt
import numpy as np
import math
import pandas as pd

from collections import defaultdict


def plot_experiment_1():
    data = pd.read_csv("output/experiment_1.csv").iloc[:, 0].values
    min_utility = min(data)
    max_utility = max(data)
    plt.hist(data, bins=range(min_utility, max_utility + 1, 50))
    plt.xlabel("Utility Change")
    plt.ylabel("Frequency")
    plt.title("Average Agent Utility Increase from Ex-Post Transfers")
    plt.savefig("output/experiment_1.png")


def plot_experiment_2():
    plt.clf()
    data = pd.read_csv("output/experiment_2.csv")
    init_budget = data.iloc[:, 0].values
    utility = data.iloc[:, 1].values
    average_budgets = defaultdict(int)
    counts = defaultdict(int)
    for i in range(len(init_budget)):
        average_budgets[init_budget[i]] += utility[i]
        counts[init_budget[i]] += 1
    for key in average_budgets:
        average_budgets[key] /= counts[key]
    init_budget, avg_utility = zip(
        *sorted(zip(list(average_budgets.keys()), list(average_budgets.values())))
    )
    plt.scatter(init_budget, avg_utility)
    # log line of best fit
    log_init_budget = np.log(init_budget)
    m, b = np.polyfit(log_init_budget, avg_utility, 1)
    plt.plot(np.exp(log_init_budget), m * log_init_budget + b, color="red")
    # add label for line of best fit

    plt.xlabel("Initial Budget")
    plt.ylabel("Utility Change")
    plt.title(
        "Average Agent Utility Increase from Ex-Post Transfers, with Wealth Inequality"
    )
    plt.savefig("output/experiment_2b.png")

    # plot initial budgets
    plt.clf()
    plt.hist(init_budget, 100)
    plt.xlabel("Initial Budget")
    plt.ylabel("Number of Agents")
    plt.title("Initial Budgets of Agents")
    plt.savefig("output/experiment_2a.png")


def plot_experiment_3():
    plt.clf()
    data = pd.read_csv("output/experiment_3.csv")
    indices = data.iloc[:, 0].values
    utility = data.iloc[:, 1].values
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(indices, utility)
    ax.set_xscale("log")
    plt.xlabel("Friction as a Proportion of Transaction Cost (log scale)")
    plt.ylabel("Improvement over RSD w/o Transfers (%)")
    plt.title("Utility Change from Ex-Post Transfers with Proportional Friction Costs")
    plt.savefig("output/experiment_3.png")


def plot_experiment_4():
    plt.clf()
    data = pd.read_csv("output/experiment_4.csv")
    indices = data.iloc[:, 0].values
    utility = data.iloc[:, 1].values
    print(len(indices), len(utility))
    print(indices, utility)
    fig = plt.figure()
    ax = fig.add_subplot(111)
    ax.plot(indices, utility)
    plt.xlabel("Flat Friction Amount")
    plt.ylabel("Improvement over RSD w/o Transfers (%)")
    plt.title("Utility Change from Ex-Post Transfers with Flat Friction Costs")
    plt.savefig("output/experiment_4.png")


def main():
    plot_experiment_1()
    plot_experiment_2()
    plot_experiment_3()
    plot_experiment_4()


if __name__ == "__main__":
    main()
