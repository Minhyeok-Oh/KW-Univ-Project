package com.project2.service;

import java.util.List;
import java.util.Map;

import javax.annotation.Resource;
import javax.inject.Inject;

import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Isolation;
import org.springframework.transaction.annotation.Transactional;
import org.springframework.web.multipart.MultipartHttpServletRequest;

import com.project2.dao.BoardDAO;
import com.project2.domain.BoardVO;
import com.project2.util.FileUtils;

@Service // create this class to bean object of root container
public class BoardServiceImpl implements BoardService {
	// find bean object for method of Bean object ID mapping
	// forced set ID fileUtils
	@Resource(name = "fileUtils")
	private FileUtils fileUtils;
	@Inject // find bean object for same name
	private BoardDAO dao; // declare BoardDAO object

	@Override
	public List<BoardVO> list(String category, int displayPost, int postNum) throws Exception {

		return dao.list(category, displayPost, postNum); // call list
	}

	@Override
	public void write(BoardVO vo, MultipartHttpServletRequest mhsRequest) throws Exception {
		dao.write(vo); // write post
		// written file information
		// mhsRequest for file process
		Map<String, Object> list = fileUtils.parseInsertFileInfo(vo, mhsRequest);
		dao.insertFile(list); // insert file information
	}

	// set transaction processing
	@Transactional(isolation = Isolation.READ_COMMITTED)
	@Override
	public BoardVO view(int bno) throws Exception {
		dao.updateviewCnt(bno); // update view count for post number
		return dao.view(bno); // view post for post number
	}

	@Override
	public void modify(BoardVO vo, MultipartHttpServletRequest mhsRequest) throws Exception {
		dao.modify(vo); // post modify
		// written file information
		// mhsRequest for file process
		Map<String, Object> list = fileUtils.parseInsertFileInfo(vo, mhsRequest);
		dao.insertFile(list); // insert file information
	}

	@Override
	public void delete(int bno) throws Exception {
		dao.delete(bno); // delete post for post number
	}

	@Override
	public int count() throws Exception {
		return dao.count(); // counting post
	}

	@Override
	public int countCate(String category) throws Exception {
		return dao.countCate(category); // counting post for category
	}

	@Override
	public List<BoardVO> listPage(int displayPost, int postNum) throws Exception {
		return dao.listPage(displayPost, postNum); // post list
	}

	@Override
	public Map<String, Object> selectFile(int bno) throws Exception {
		// TODO Auto-generated method stub
		return dao.selectFile(bno); // select file for post number
	}

	@Override
	public void deleteFile(int file_no) throws Exception {
		// TODO Auto-generated method stub
		dao.deleteFile(file_no); // delete file for file number
	}

}