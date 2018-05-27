#ifndef _QC_include_math_h_ //header guard
#define _QC_include_math_h_

namespace QCMath{
	
	inline double sqrt(double number){
		double y = number;
		double x2 = y * 0.5;
		std::int64_t i = *(std::int64_t *) &y;
		i = 0x5fe6eb50c7b537a9 - (i >> 1);
		y = *(double *) &i;
		y = y * (1.5 - (x2 * y * y));
		y = y * (1.5 - (x2 * y * y));   // 2nd iteration, this can be removed
		return y * number;
	}
};
  
#endif // header guard