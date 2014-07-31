/*-
 * Copyright 2014 Diomidis Spinellis
 *
 *   Licensed under the Apache License, Version 2.0 (the "License");
 *   you may not use this file except in compliance with the License.
 *   You may obtain a copy of the License at
 *
 *       http://www.apache.org/licenses/LICENSE-2.0
 *
 *   Unless required by applicable law or agreed to in writing, software
 *   distributed under the License is distributed on an "AS IS" BASIS,
 *   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *   See the License for the specific language governing permissions and
 *   limitations under the License.
 */

#ifndef CMETRICSCALCULATOR_H
#define CMETRICSCALCULATOR_H

#include <iostream>

#include "CharSource.h"
#include "QualityMetrics.h"

/** Collect quality metrics from C-like source code */
class CMetricsCalculator {
private:
	CharSource src;
	QualityMetrics qm;
	void calculate_metrics_loop();
	bool calculate_metrics_switch();
public:
	CMetricsCalculator(std::istream &s = std::cin) : src(s) {}
	void calculate_metrics() {
		calculate_metrics_loop();
		qm.set_nchar(src.get_nchar());
	}
	const QualityMetrics& get_metrics() const { return qm; }
};
#endif /* CMETRICSCALCULATOR_H */
