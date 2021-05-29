<%@ taglib uri="http://java.sun.com/jsp/jstl/core" prefix="c"%>
<%@ page language="java" contentType="text/html; charset=UTF-8"
	pageEncoding="UTF-8"%>
<!doctype html>
<html>

<head>
<title>천둥마켓</title>
<style>
body{
	margin:0;
}
html, body{
	height:100%;
}
table{table-layout:fixed;}
.container {
	
}
th, td{
	border: 1px solid black;
	text-align : center;
}
* {
	box-sizing: border-box;
}

.container {
	border: 1px solid black;
}

.container>* {
	border: 1px solid black;
}

.container>.content>* {
	border: 1px solid black;
}

.container .content {
	padding-left: 200px;
	padding-right: 150px;
	overflow: hidden;
	
	
}

.container .content>* {
	float: left;
	padding-bottom: 2500px;
	margin-bottom: -2500px;
}

.container .content main {
	width: 100%;
	
}

.container .content nav {
	width: 200px;
	margin-left: -100%;
	left: -200px;
	position: relative;
}

.container .content aside {
	width: 150px;
	margin-right: -150px;
	
}

.container footer {
	clear: both;
}

@media ( max-width :599px) {
	.container .content {
		padding-left: 0;
		padding-right: 0;
		overflow: visible;
		
	}
	.container .content>* {
		float: none;
		padding-bottom: 0;
		margin-bottom: 0;
	}
	.container .content main {
		width: 100%;
		
		
	}
	.container .content nav {
		width: auto;
		margin-left: 0;
		left: 0;
		position: relative;
	}
	.container .content aside {
		width: auto;
		margin-right: 0;
	}
}
</style>
</head>

<body>
	<div class="container">
		<header>
			<h3>천둥마켓</h3>
		</header>
		<section class="content" style="height:100vh">
			<main><table width="800px" style="border-collapse:collapse; margin-left:auto; margin-right:auto; margin-top:30px; border:1px solid black"><th colspan="4" style="height:40px; vertical-align:top; text-align:left;">toys</th>
			<tr>
				<th rowspan="3"></th>
				<td style="height:20px;">상품설명</td>
				<td>가격</td>
				<td rowspan="2">이름:<br>조회수:<br>작성일:</td>				
			</tr>
			<tr>
				<td rowspan="2" style="height:100px;"></td>
				<td rowspan="2"></td>
			</tr>
			<tr>
				<td style="height:40px;"></td>				
			</tr>
			</table></main>
			<nav>
				<div style="border : 1px solid black">카테고리</div>
				<ul>
					<li>item</li>
					<li>item</li>
					<li>item</li>
				</ul>
			</nav>
			<aside></aside>
		</section>
	</div>
</body>

</html>