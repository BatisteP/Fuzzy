<div id="fuzzy framework">
	<h1>FUZZY FRAMEWORK</h1>
</div>


<div id="fuzzy membership functions">
	<h2>FUZZY MEMBERSHIP FUNCTIONS</h2>
</div>

<div id="triangle head">
	<h3>Triangular function :</h3>
	<h5>Defined by a lower limit a, an upper limit b, and a value m, where a < m < b</h5>
</div>
<div id="triangle">
	<p align="center">
	  <img src="doc/assets/img/desctri_en.gif" title="Triangular function">
	  <img src="doc/assets/img/funtri.jpg" alt="Triangular">
	</p>
</div>

<div id="trapezoidal head">
	<h3>Trapezoidal function :</h3>
	<h5>Defined by a lower limit a, an upper limit d, a lower support limit b, and an upper support limit c, where a < b < c < d</h5>
</div>
<div id="trapezoidal">
	<p align="center">
	  <img src="doc/assets/img/desctrap_en.gif" title="Trapezoidal function">
	  <img src="doc/assets/img/funtrap.jpg" alt="Trapezoidal">
	</p>
</div>

<div id="trapezoidal remark">
	<h3>Trapezoidal function remark :</h3>
	<h5>There are two special cases of a trapezoidal function, which are called R-functions and L-functions:</h5>
</div>
<div>
	<ul>
		<li>
			<h5>R-functions: with parameters a = b = - ∞ </h5>
			<div id="R-functions">
				<p align="center">
				  <img src="doc/assets/img/desctrapR_en.gif" title="Trapezoidal Right function">
				  <img src="doc/assets/img/funtrapR.jpg" alt="Trapezoidal Right">
				</p>
			</div>
		</li>
		<li>
			<h5>L-Functions: with parameters c = d = + ∞ </h5>
			<div id="L-Functions">
				<p align="center">
				  <img src="doc/assets/img/desctrapL_en.gif" title="Trapezoidal Left function">
				  <img src="doc/assets/img/funtrapL.jpg" alt="Trapezoidal Left">
				</p>
			</div>
		</li>
	</ul>
</div>

<div id="gaussian head">
	<h3>Gaussian function:</h3>
	<h5>Defined by a central value m and a standard deviation k > 0. The smaller k is, the narrower the “bell” is.</h5>
</div>
<div id="gaussian">
	<p align="center">
		<img src="doc/assets/img/descgaus.gif" title="Gaussian function">
	  	<img src="doc/assets/img/fungaus.jpg" alt="Gaussian">
	</p>
</div>

<div>
	<h5>For more informations about fuzzy mumbership functions </h5>
	<a href="http://www.dma.fi.upm.es/recursos/aplicaciones/logica_borrosa/web/fuzzy_inferencia/funpert_en.htm">visit</a>
</div>


<div id="fuzzy operators">
	<h2>FUZZY OPERATORS</h2>
</div>

<div id="basic operators head">
	<h3>Basic operators :</h3>
	<h5>As in classical logic, in fuzzy logic there are three basic operations on fuzzy sets: union, intersection and complement.</h5>
</div>
<div>
	<ul>
		<li>
			<h4>Union : </h4>
			<h5>Let µA and µB be membership functions that define the fuzzy sets A and B, respectively, on the universe X.</h5>
			<h5>The union of fuzzy sets A and B is a fuzzy set defined by the membership function:</h5>
			<div id="union">
				<p align="center">
					<img src="doc/assets/img/union.png" title="union operation">
				</p>
			</div>
		</li>
		<li>
			<h4>Intersection : </h4>
			<h5>Let µA and µB be membership functions that define the fuzzy sets A y B, respectively, on the universe X.</h5>
			<h5>The intersection of fuzzy sets A and B is a fuzzy set defined by the membership function:</h5>
			<div id="intersection">
				<p align="center">
					<img src="doc/assets/img/intersection.png" title="intersection operation">
				</p>
			</div>
		</li>
		<li>
			<h4>Complement : </h4>
			<h5>Let µA be a membership function that defines the fuzzy set A, on the universe X.</h5>
			<h5>The complement of A is a fuzzy set defined by the membership function:</h5>
			<div id="union">
				<p align="center">
					<img src="doc/assets/img/complement.png" title="complement operation">
				</p>
			</div>
		</li>
	</ul>
</div>