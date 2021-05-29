package com.project2.service;

import java.util.List;
import java.util.Map;

import org.springframework.web.multipart.MultipartHttpServletRequest;

import com.project2.domain.BoardVO;

public interface BoardService {
	// board list for category
	public List<BoardVO> list(String category, int displayPost, int postNumy) throws Exception;
	// write a post
	public void write(BoardVO vo, MultipartHttpServletRequest mhsRequest) throws Exception;
	// view for post number
	public BoardVO view(int bno) throws Exception;
	// post modify
	public void modify(BoardVO vo, MultipartHttpServletRequest mhsRequest) throws Exception;
	// post delete
	public void delete(int bno) throws Exception;
	// the number of post counting
	public int count() throws Exception;
	// the number of post counting for category
	public int countCate(String category) throws Exception;
	// board list
	public List<BoardVO> listPage(int displayPost, int postNum) throws Exception;
	// select file for post number
	public Map<String, Object> selectFile(int bno) throws Exception;
	// file delete for file number
	public void deleteFile(int file_no) throws Exception;
}
